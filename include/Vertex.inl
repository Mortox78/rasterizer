#ifndef __VERTEX_INL__
#define __VERTEX_INL__

#include "Vertex.h"

inline Vertex::Vertex(const float& x, const float& y, const float& z)
{
    position 	= {x, y, z};
	normal		= position;
	normal.normalize();
	UV			= {-1,-1};
}

inline Vertex::Vertex(const Vertex& copyVertex):
	UV		 {copyVertex.UV},
	position {copyVertex.position},
	normal   {copyVertex.normal},
	color    {copyVertex.color}
{}


// get our pixel's pos in the 3D environment
inline void Vertex::get_barycentric_vertex(const Vertex& ver1, const Vertex& ver2, const Vertex& ver3, const Vec3& weight)
{
	position = (ver1.position * weight.x) + (ver2.position * weight.y) + (ver3.position * weight.z);
	normal   = (ver1.normal * weight.x)   + (ver2.normal * weight.y)   + (ver3.normal * weight.z);
	normal.normalize();

	UV 		= (ver1.UV * weight.x) + (ver2.UV * weight.y) + (ver3.UV * weight.z);
	color 	= (ver1.color * weight.x) + (ver2.color * weight.y) + (ver3.color * weight.z);
}



#endif //__VERTEX_INL__
