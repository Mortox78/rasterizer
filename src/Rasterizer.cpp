#include <iostream>
#include "Rasterizer.h"
#include "vector.hpp"
#include <SDL2/SDL.h>

//===========================================================================//

Rasterizer::Rasterizer()
{
    init_SDL();
    window = create_window();
    renderer = create_renderer();
	SDL_GL_SetSwapInterval(0);
}

Rasterizer::~Rasterizer()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

//===========================================================================//

Matrix4<float> Rasterizer::CreateOrthoMatrix(const float& right, const float&  left, const float&  top, const float&  bottom, const float&  far, const float&  near) const
{
	Matrix4<float> OrthoMatrix = Matrix<float,4,4>::identity();

	if (right - left != 0)
	{
		OrthoMatrix[0][0] = 2/(right - left);
		OrthoMatrix[0][3] = (right + left)/(right - left);
		OrthoMatrix[0][3] *= -1;
	}
	if (top - bottom != 0)
	{
		OrthoMatrix[1][1] = 2/(top - bottom);
		OrthoMatrix[1][3] = (top + bottom)/(top - bottom);
		OrthoMatrix[1][3] *= -1;
	}
	if (far - near != 0)
	{
		OrthoMatrix[2][2] = 2/(far - near);
		OrthoMatrix[2][3] = (far + near)/(far - near);
		OrthoMatrix[2][3] *= -1;
	}

	OrthoMatrix = OrthoMatrix.transponate();

	return OrthoMatrix;
}

Matrix4<float> Rasterizer::CreatePerspectiveMatrix(const int&  width, const int& height, const float& near, const float& far, const float& fov) const
{
	Matrix4<float> perspectiveMatrix = Matrix<float,4,4>::identity();

	float xmax, ymax, zmax;
	float aspect = (float)width/height;
	ymax  = tanf(degrees_to_radian(fov)/2);
	xmax  = ymax * aspect;
	zmax  = (far - near);


	perspectiveMatrix[0][0] = xmax == 0 ? 1 : 1/xmax;
	perspectiveMatrix[1][1] = ymax == 0 ? 1 : 1/ymax;
	perspectiveMatrix[2][2] = zmax == 0 ? 1 : -((far + near) /zmax);
	perspectiveMatrix[2][3] = zmax == 0 ? -1 : -((2 * near * far) / zmax);
	perspectiveMatrix[3][2] = -1;
	perspectiveMatrix[3][3] = 0;

	perspectiveMatrix = perspectiveMatrix.transponate();

	return perspectiveMatrix;
}

//===========================================================================//

void Rasterizer::init_SDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("SDL_Init error: %s", SDL_GetError());
		return;
	}

	atexit(SDL_Quit); // Tell the program to call SDL_Quit() when program ends
}

SDL_Window* Rasterizer::create_window()
{
	SDL_Window* window = SDL_CreateWindow("Rasterizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		SDL_Log("SDL_CreateWindow error: %s", SDL_GetError());
		return NULL;
	}
	else
	{
		return window;
	}
}

SDL_Renderer* Rasterizer::create_renderer()
{
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		SDL_Log("SDL_CreateRenderer error: %s", SDL_GetError());
		return NULL;
	}
	else
	{
		return renderer;
	}
}

//===========================================================================//

void Rasterizer::RenderScene(Scene* pScene, FrameBuffer* pTarget, const Camera& cam)
{
	pTarget->pixels_clear();

#pragma omp parallel for
	for (unsigned int i = 0; i < pScene->entities.size(); ++i)
	{
		draw_entity(pScene->entities[i], pTarget, pScene->lights, cam);
	}

	pTarget->display(renderer);
    SDL_RenderPresent(renderer);
}

void Rasterizer::draw_triangle (const Vertex triangleVertices[3], FrameBuffer* frameBuffer, const std::vector<Light>& lights, const Texture* texMesh)const
{
	//Getting the screen coordinates of the triangleVertices
	Vec4				screenCoords[3];
	Vec3               	screenCoordsW;

	for (int i = 0; i < 3; ++i)
	{
		screenCoords  [i]	= frameBuffer->view_port * projMatrix * triangleVertices[i].position;
		screenCoordsW [i]   = screenCoords[i].w;
		screenCoords  [i].homogenize();
	}

	// back-face culling
	if (((screenCoords[2] - screenCoords[0]) ^ (screenCoords[1] - screenCoords[0])).z <= 0.f)
		return;

	// setup barycentric variables
	Vec4 vec_1_2 = screenCoords[1] - screenCoords[0];
	Vec4 vec_1_3 = screenCoords[2] - screenCoords[0];

	Vec3 weights;
	float crossProduct_Vec12_Vec13 = (vec_1_2 ^ vec_1_3).z;

	// get the barycentrics limits (with dirty clipping)
	const int xmin = std::max((int)std::min(screenCoords[0].x,std::min(screenCoords[1].x,screenCoords[2].x)), 0);
	const int xmax = std::min((int)std::max(screenCoords[0].x,std::max(screenCoords[1].x,screenCoords[2].x)), SCREEN_WIDTH  - 1);
	const int ymin = std::max((int)std::min(screenCoords[0].y,std::min(screenCoords[1].y,screenCoords[2].y)), 0);
	const int ymax = std::min((int)std::max(screenCoords[0].y,std::max(screenCoords[1].y,screenCoords[2].y)), SCREEN_HEIGHT - 1);
	

	for (int y = ymin; y <= ymax; y++)
	{
		for (int x = xmin; x <= xmax; x++)
		{
			Vec4 pixelPos = Vec4((float)x,(float)y,0);
			// Vec between current pixel and the first vertex
			Vec4 dPos1 = pixelPos - screenCoords[0];

			// Check if the current pixel is inside our triangle (in order to draw it)
			weights[1] = (dPos1   ^ vec_1_3).z / crossProduct_Vec12_Vec13;
			weights[2] = (vec_1_2 ^ dPos1).z   / crossProduct_Vec12_Vec13;
		
			// If the pixel is in the triangle
			if ((weights[1] >= 0) && (weights[2] >= 0) && (weights[1] + weights[2] <= 1))
	    	{			
				weights[0] = 1 - weights[1] - weights[2];
				
				// get the z of our current pixel
				float z = (screenCoords[0].z * weights[0]) + (screenCoords[1].z * weights[1]) + (screenCoords[2].z * weights[2]);

				// if pixel's z can enter in z_buffer, we draw the pixel
				if (frameBuffer->z_buffer[(y * SCREEN_WIDTH) + x] > z)
				{
					weights[0] /= screenCoordsW[0];
					weights[1] /= screenCoordsW[1];
					weights[2] /= screenCoordsW[2];

					weights /= (weights[0] + weights[1] + weights[2]);

					// get the current pixel's pos
					Vertex pos_ver;
					pos_ver.get_barycentric_vertex(triangleVertices[0], triangleVertices[1], triangleVertices[2], weights);
					// use the texture if there is a loaded one
					if (texMesh != nullptr)
					{
						pos_ver.color 		= texMesh->bind_texture(pos_ver.UV);
					}
					
					float intensity = 0;

					for (const Light& light : lights)
					{
						// apply light on our pixel
						intensity += light.shade(pos_ver);
					}

					pos_ver.color = pos_ver.color * std::min(intensity,1.0f);
					// WIREFRAME ECO+
					//if (weight.x < 0.01 || weight.y < 0.01 || weight.z < 0.01)
					//	pos_ver.color = {255, 255, 255, 255};
					
					// add the pixel in our frameBuffer
		        	frameBuffer->SetPixelColor(x, y, pos_ver.color);
					frameBuffer->z_buffer[(y * SCREEN_WIDTH) + x] = z;
				}
			}
		}
	}
}

void Rasterizer::draw_entity(const Entity& entity, FrameBuffer* frameBuffer, std::vector<Light>& lights, const Camera& cam)
{
	std::vector<Light> worldLights = lights;

	for (unsigned int i = 0; i < worldLights.size(); ++i)
	{
		worldLights[i].position = cam.inverseCamMatrix * worldLights[i].position;
	}

	for (unsigned int i = 0; i < entity.mesh->indices.size() - 2; i += 3)
	{
		Vertex triangleVertices[3];
			
		Matrix4<float> modelView = cam.inverseCamMatrix * entity.transformation;

		for (int j = 0; j < 3; ++j)
		{
			// Get the vertex
			triangleVertices[j] = entity.mesh->vertices[entity.mesh->indices[i + j]];
			// Apply transformation matrix and camera to the vertex's position
			triangleVertices[j].position = modelView * Vec4(triangleVertices[j].position);
			// Apply transformation matrix and camera to vertex's normal
			triangleVertices[j].normal   = (modelView *  Vec4(triangleVertices[j].normal,0.0f)).normalize();
			// Apply UV pos from UVlist to vertices
			if (entity.mesh->pTexture != nullptr)
			{
				triangleVertices[j].UV 		 = entity.mesh->UVList[i + j];
			}
		}

		draw_triangle(triangleVertices, frameBuffer,worldLights, entity.mesh->pTexture);
	}
}
