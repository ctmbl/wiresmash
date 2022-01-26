#ifndef PHX_COLLISION_H
#define PHX_COLLISION_H

// dependencies
#include <tuple>
#include <vector>
#include "entity/entity.h"
#include "entity/strategies/physical_entity.h"
#include "phx/hitbox.h"


struct Collider
{
    Entity* ettColliding;
    Entity* ettInto ;
    std::pair<int, int> colVector;
};

std::pair<int, int> checkCollisionEntities(Entity, Entity);

std::vector<Collider> checkCollision(std::vector<Entity>);


#endif
