#include "Mesh.h"
#include "Entity.h"

Entity::Entity():
    mesh {nullptr},
    transformation {Matrix<float,4,4>::identity()}
{
}

Entity::Entity(Mesh* _mesh):
    mesh {_mesh},
    transformation {Matrix<float,4,4>::identity()}
{
}


Entity::~Entity()
{
}
