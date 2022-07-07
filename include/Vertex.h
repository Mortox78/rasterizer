#ifndef _VERTEX_H_
#define _VERTEX_H_

#include "matrix.h"
#include "Color.h"

class Vertex
{
    public:
        inline Vertex(const float& x = 0, const float& y = 0, const float& z = 0);
        inline Vertex(const Vertex& copyVertex);
        inline ~Vertex(){}

        Vec2    UV;
        Vec3    position;
		Vec3    normal;
        Color   color = {255,255,255,255};


        // get our pixel's pos in the 3D environment
        inline void get_barycentric_vertex(const Vertex& ver1, const Vertex& ver2, const Vertex& ver3, const Vec3& weight);
};

#include "Vertex.inl"

#endif
