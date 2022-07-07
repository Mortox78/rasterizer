#ifndef __LIGHT_HPP__
#define __LIGHT_HPP__

#include "Vertex.h"

class Light
{
	private:
		float 	ambientComponent;
		float 	diffuseComponent;
		float 	specularComponent;

	public:
		Vec3 	position;

		Light(const Vec3& position = Vec3(0.0f,0.0f,0.0f), float ambient = 0, float diffuse = 0, float specular = 0);
		Light(const Light& CopyLight);
		~Light();

		float shade (const Vertex& vertex)const;
};


inline float	Light::			shade (const Vertex& vertex)const
{
	float alpha = 20;

	// ambient
	float ambient_intensity = ambientComponent;

	// diffuse
	Vec3 to_light 	= position - vertex.position;
	to_light.normalize();

	float cos_btw_light_nor = std::max((to_light , vertex.normal), 0.f);

	float diffuse_intensity = 1 * diffuseComponent * cos_btw_light_nor;

	// specular
	float cos_btw_view_reflect = 0;
	Vec3 view = (vertex.position).normalize(); 
	Vec3 half_angle_vect = (to_light + view).normalize();

	cos_btw_view_reflect = std::max((half_angle_vect , vertex.normal), 0.f);

	float specular_intensity = 1 * specularComponent * powf(cos_btw_view_reflect,alpha);

	// calculate intensity
	float intensity = std::min(1.0f,ambient_intensity + diffuse_intensity + specular_intensity);

	return intensity;
}

#endif //__LIGHT_HPP__
