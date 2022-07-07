#include <cmath>
#include <iostream>
#include "Mesh.h"
#include "Vertex.h"

Mesh::Mesh()
{
	pTexture = nullptr;
}

Mesh* Mesh::CreateCube()
{
    Mesh* cube = new Mesh;

    cube->CreateCubeVertices(cube);
    cube->CreateCubeIndicesAndUV(cube);

    return cube;
}

Mesh* Mesh::CreateSphere(int latitude, int longitude)
{
	Mesh* sphere = new Mesh;

	float PI_2 = 2 * M_PI;
	
	sphere->pushBack_Vertex(0.0f,1.0f,0.0f);
	sphere->vertices[0].color = {50,175,255,255};
	for (int i = 0; i < latitude - 1; i++)
	{
		float cospolar = cosf(M_PI * (float)(i + 1) / (float)latitude);
		float sinpolar = sinf(M_PI * (float)(i + 1) / (float)latitude);

		for (int j = 0; j < longitude; j++)
		{
			float cosazimuth = cosf(PI_2 * (float)j / (float)longitude);
			float sinazimuth = sinf(PI_2 * (float)j / (float)longitude);

			float x = sinpolar * cosazimuth;
			float y = cospolar;
			float z = sinpolar * sinazimuth;
			sphere->pushBack_Vertex(x,y,z);
			sphere->vertices[(i*longitude)+j].color = {50,175,255,255};
		}
	}
	sphere->pushBack_Vertex(0.0f,-1.0f,0.0f);
	sphere->vertices[sphere->vertices.size() - 1].color = {50,175,255,255};

	for (int j = 0; j < longitude; j++)
		sphere->pushBack_TriangleIndices(0,(j + 1) % longitude + 1, j + 1);

	for (int i = 0; i < latitude - 2; i++)
	{
		int aStart = i *  longitude+ 1;
		int bStart = (i + 1) * longitude + 1;

		for (int j = 0; j < longitude; j++)
		{
			int a = aStart + j;
			int b = aStart + (j + 1) % longitude;
			int c = bStart + j;
			int d = bStart + (j + 1) % longitude;
			sphere->pushBack_TriangleIndices(a,b,c);
			sphere->pushBack_TriangleIndices(c,b,d);
		}
	}
    //delete oui;
	int max = sphere->vertices.size() - 1;
	
	for (int i = 0; i < longitude; i++)
	{
		sphere->pushBack_TriangleIndices(max,i + longitude * (latitude - 2) + 1,
			   								(i + 1) % longitude + longitude * (latitude - 2) + 1);
	}

	return sphere;
}


void Mesh::pushBack_Vertex(float x, float y, float z)
{
    vertices.push_back({x, y, z});
}

void Mesh::pushBack_Indice(int index)
{
    indices.push_back(index);
}

void Mesh::pushBack_TriangleIndices(int index1, int index2, int index3)
{
    indices.push_back(index1);
    indices.push_back(index2);
    indices.push_back(index3);
}

void Mesh::pushBack_TriangleUV(const Vec2& UV1, const Vec2& UV2, const Vec2& UV3)
{
	UVList.push_back(UV1);
	UVList.push_back(UV2);
	UVList.push_back(UV3);
}

void Mesh::CreateCubeVertices(Mesh* cube)
{
    // +x || +z
    cube->pushBack_Vertex(0.5f,     0.5f,       0.5f);          // 0
    cube->pushBack_Vertex(0.5f,     -0.5f,      0.5f);          // 1
    // -x || +z                                                 //
    cube->pushBack_Vertex(-0.5f,    0.5f,       0.5f);          // 2
    cube->pushBack_Vertex(-0.5f,    -0.5f,      0.5f);          // 3
    // -x || -z                                                 //
    cube->pushBack_Vertex(-0.5f,    0.5f,       -0.5f);         // 4
    cube->pushBack_Vertex(-0.5f,    -0.5f,      -0.5f);         // 5
    // +x || -z                                                 //
    cube->pushBack_Vertex(0.5f,     0.5f,       -0.5f);         // 6
    cube->pushBack_Vertex(0.5f,     -0.5f,      -0.5f);         // 7
}


void Mesh::CreateCubeIndicesAndUV(Mesh* cube)
{
    // Faces
    cube->pushBack_TriangleIndices(1, 0, 2);
    cube->pushBack_TriangleIndices(1, 2, 3);

    cube->pushBack_TriangleIndices(3, 2, 4);
    cube->pushBack_TriangleIndices(3, 4, 5);

    cube->pushBack_TriangleIndices(5, 4, 6);
    cube->pushBack_TriangleIndices(5, 6, 7);

    cube->pushBack_TriangleIndices(7, 6, 0);
    cube->pushBack_TriangleIndices(7, 0, 1);

    // Top and bottom
    cube->pushBack_TriangleIndices(6, 4, 0);
    cube->pushBack_TriangleIndices(0, 4, 2);

    cube->pushBack_TriangleIndices(5, 7, 1);
    cube->pushBack_TriangleIndices(5, 1, 3);

	// UV indices
	
	// Faces
	for (unsigned int i = 0; i < 4; ++i)
	{
		cube->pushBack_TriangleUV(BOTTOM_RIGHT_UV, TOP_RIGHT_UV, TOP_LEFT_UV);
		cube->pushBack_TriangleUV(BOTTOM_RIGHT_UV, TOP_LEFT_UV, BOTTOM_LEFT_UV);
	}

	// Top and bottom	
	cube->pushBack_TriangleUV(TOP_RIGHT_UV, TOP_LEFT_UV, BOTTOM_RIGHT_UV);
	cube->pushBack_TriangleUV(BOTTOM_RIGHT_UV, TOP_LEFT_UV, BOTTOM_LEFT_UV);

	cube->pushBack_TriangleUV(BOTTOM_LEFT_UV, BOTTOM_RIGHT_UV, TOP_RIGHT_UV);
	cube->pushBack_TriangleUV(BOTTOM_LEFT_UV, TOP_RIGHT_UV, TOP_LEFT_UV);
}

Mesh* Mesh::CreateTriangle()
{
    Mesh* oui = new Mesh;
    oui->pushBack_Vertex(0.0f, 0.0f, 0);
    oui->pushBack_Vertex(1.0f, 0.0f, 0);
    oui->pushBack_Vertex(0.0f, 1.0f, 0);
    oui->pushBack_TriangleIndices(0, 1, 2);
	
	oui->vertices[0].color = {255, 0, 0, 255};
	oui->vertices[1].color = {0, 255, 0, 255};
	oui->vertices[2].color = {0, 0, 255, 255};

    return oui;
}
