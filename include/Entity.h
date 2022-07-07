#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Mesh.h"

class Entity
{
    public:
        Entity();
        Entity(Mesh* mesh);
        ~Entity();

        Mesh* mesh;
        Matrix4<float> transformation;
};



#endif
