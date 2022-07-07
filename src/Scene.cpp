#include "Scene.h"

#include <vector>
#include "Entity.h"




Scene::~Scene()
{
    entities.clear();
}