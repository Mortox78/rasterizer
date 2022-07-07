#ifndef _MESH_H_
#define _MESH_H_

#include "Vertex.h"
#include "Texture.hpp"
#include "vector.hpp"
#include <vector>


class Mesh
{
    private:
        void    CreateCubeVertices(Mesh* cube);
        void    CreateCubeIndicesAndUV(Mesh* cube);

        void    pushBack_Vertex(float x, float y, float z);
        void    pushBack_Indice(int index);
        void    pushBack_TriangleIndices(int index1, int index2, int index3);
        void    pushBack_TriangleUV(const Vec2& UV1, const Vec2& UV2, const Vec2& UV3);

    public:
        std::vector<Vertex> vertices;
        std::vector<int>    indices;
        std::vector<Vec2>   UVList;
        Texture*            pTexture;

        Mesh();
        //~Mesh(){}
      
        static Mesh* CreateTriangle();
        static Mesh* CreateCube();
		static Mesh* CreateSphere(int latitude, int longitude);
};



#endif
