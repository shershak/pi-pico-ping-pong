#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H

#include "ecs/Entity.h"
#include "game/components/CPosition.h"
#include "game/components/CVelocity.h"

class BallMovementSystem
{
public:
  void update(Entity &entity, int deltaTime)
  {
    if (entity.position && entity.velocity)
    {
      entity.position->x += entity.velocity->vx * deltaTime;
      entity.position->y += entity.velocity->vy * deltaTime;
    }
  }
};

#endif // MOVEMENT_SYSTEM_H