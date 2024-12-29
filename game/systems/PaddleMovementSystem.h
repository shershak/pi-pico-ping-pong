#ifndef PADDLE_MOVEMENT_SYSTEM_H
#define PADDLE_MOVEMENT_SYSTEM_H

#include "ecs/Entity.h"
#include "game/components/CPosition.h"
#include "game/components/CVelocity.h"
#include "core/buttons/ButtonManager.h"

class PaddleMovementSystem
{
public:
  PaddleMovementSystem(ButtonManager &buttons) 
    : buttons(buttons) {}

  void update(Entity &paddle, ButtonManager::BUTTON up, ButtonManager::BUTTON down, int deltaTime)
  {
    if (paddle.position && paddle.shape)
    {
      if (buttons.is_pressed(up))
      {
        if (paddle.position->y > 0)
        {
          paddle.position->y -= 1 * deltaTime;
        }
      }
      if (buttons.is_pressed(down))
      {
        if (paddle.position->y < 63 - paddle.shape->height)
        {
          paddle.position->y += 1 * deltaTime;
        }
      }
    }
  }

private:
  ButtonManager &buttons;
};

#endif // PADDLE_MOVEMENT_SYSTEM_H