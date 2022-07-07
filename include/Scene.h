#ifndef _SCENE_H_
#define _SCENE_H_

#include "Entity.h"
#include "Light.hpp"

class Scene
{
    public:
        Scene(){}
        ~Scene();

        std::vector<Entity> entities;
		std::vector<Light>	lights;

};


#endif
