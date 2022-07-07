#include <cmath>
#include "Light.hpp"

Light:: 	Light	(const Vec3& pos, float ambient, float diffuse, float specular):
	ambientComponent	{ambient},
	diffuseComponent	{diffuse},
	specularComponent	{specular},
	position 			{pos}
{}

Light::		Light	(const Light& CopyLight):
	ambientComponent	{CopyLight.ambientComponent},
	diffuseComponent	{CopyLight.diffuseComponent},
	specularComponent	{CopyLight.specularComponent},
	position			{CopyLight.position}
{}

Light::		~Light	()
{}

