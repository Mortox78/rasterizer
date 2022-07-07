#include <iostream>
#include <memory>
#include "matrix.h"
#include "Rasterizer.h"
#include "Light.hpp"
#include "Texture.hpp"
#include "Camera.hpp"

#define __CALC_FPS__

int main()
{
    Rasterizer 		game;
    Scene 			scene;
	Camera 			cam;
	Texture 		tex("crate.png");
   	FrameBuffer 	frameBuffer(game.renderer,SCREEN_WIDTH,SCREEN_HEIGHT);
    bool 			running = true;
    SDL_Event 		event;

	// Entities
    #if 0
    std::unique_ptr<Mesh> triangle(Mesh::CreateTriangle());
    scene.entities.push_back(Entity(triangle.get()));
    #endif

    #if 1
	// Create 4 boxes
	std::unique_ptr<Mesh> cube(Mesh::CreateCube());
	for (int i = 0; i < 4; ++i)
	{
    	scene.entities.push_back(Entity(cube.get()));
		scene.entities[i].mesh->pTexture = &tex;
	}

	// set transformation matrix
    Matrix4<float> matCube;
    Vec3 translate1(0.f, 0.f, 0.f);
	Vec3 rot1(0.f, 0.f, 0.f);
    Vec3 scale1(1.f);

	// set every TRS matrix for our boxes
	scene.entities[0].transformation = Matrix4<float>::CreateTRSMatrix(scale1, rot1, { 1.f,  1.f, 0.f});
	scene.entities[1].transformation = Matrix4<float>::CreateTRSMatrix(scale1, rot1, {-1.f,  1.f, 0.f});
	scene.entities[2].transformation = Matrix4<float>::CreateTRSMatrix(scale1, rot1, { 1.f, -1.f, 0.f});
	scene.entities[3].transformation = Matrix4<float>::CreateTRSMatrix(scale1, rot1, {-1.f, -1.f, 0.f});

	std::unique_ptr<Mesh>sphere(Mesh::CreateSphere(5,5));
	scene.entities.push_back(sphere.get());
	scene.entities.push_back(sphere.get());
	scene.entities.push_back(sphere.get());
	#else
	std::unique_ptr<Mesh>sphere(Mesh::CreateSphere(40,40));
	scene.entities.push_back(sphere.get());
    #endif


	// Projection or ortho matrix
	#if 1
	game.projMatrix = game.CreatePerspectiveMatrix(frameBuffer.getWidth(),frameBuffer.getHeight(),0.1,2,60);
	#else
	float aspect = (float)frameBuffer.getHeight()/frameBuffer.getWidth(); 
    game.projMatrix = game.CreateOrthoMatrix(-1,1,-aspect,aspect,0.01,2);
	#endif

	// setup light
	Light l = Light(Vec3(0,0,0),0.4,0.4,0.2);
	scene.lights.push_back(l);
	scene.lights.push_back(Light(Vec3(0,0,0),0.0,0.4,0.2));
	scene.lights.push_back(Light(Vec3(0,0,0),0.0,0.4,0.2));
	#ifdef __CALC_FPS__
	float oldTimeSinceStart = 0;
	unsigned int frame = 0;
	#endif

	float angle = 0;
	//calculates delta time
	float time 				= 0;
    while (running)
    {
	

		//we look for the time of execution since we initialized SDL
    	float current_time 		= SDL_GetTicks();
		//and here we calculate the time of execution of the loop
    	float deltaTime			= (time > 0) ? ((current_time - time) / 1000.f) : 1.0f / 60.0f;
    	time 					= current_time;
	
		#ifdef __CALC_FPS__	
		oldTimeSinceStart += deltaTime;
		frame++;

		if (oldTimeSinceStart > 1)
		{
			std::cout << ((float)frame/oldTimeSinceStart) << std::endl;
			oldTimeSinceStart = 0;
			frame = 0;
		}

		#endif

		// rotate lights around 0,0,0
		scene.lights[0].position.x = cos((angle * M_PI) / 180.f) * 2;
		scene.lights[0].position.z = sin((angle * M_PI) / 180.f) * 2;
		scene.lights[1].position.y = sin((angle * M_PI) / 180.f) * 3;
		scene.lights[1].position.x = cos((angle * M_PI) / 180.f) * 3;
		scene.lights[2].position.y = sin((-angle * M_PI) / 180.f) * 2;
		scene.lights[2].position.z = cos((-angle * M_PI) / 180.f) * 2;

		// move the sphere which represent the light
		scene.entities[4].transformation = Matrix4<float>::CreateTRSMatrix(Vec3(0.05,0.05,0.05), rot1, scene.lights[0].position);
		scene.entities[5].transformation = Matrix4<float>::CreateTRSMatrix(Vec3(0.05,0.05,0.05), rot1, scene.lights[1].position);
		scene.entities[6].transformation = Matrix4<float>::CreateTRSMatrix(Vec3(0.05,0.05,0.05), rot1, scene.lights[2].position);

		angle += deltaTime * 50.0f;
		cam.manage_cam(game, deltaTime);

		// inputs
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN)
                switch (event.key.keysym.sym)
                { 
                    case SDLK_ESCAPE:
                        running = false;
						break;
					default:
						break;	
				}
            else if (event.type == SDL_QUIT)
                running = false;
        }

		// Render the scene
        game.RenderScene(&scene, &frameBuffer, cam);
        SDL_Delay(1);
    }

    SDL_Quit();

    return 0;
}
