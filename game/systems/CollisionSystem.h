#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include "ecs/Entity.h"
#include "game/components/CPosition.h"
#include "game/components/CVelocity.h"
#include "core/buttons/ButtonManager.h"

class CollisionSystem
{
public:
  void update(Entity &ball, Entity &paddle1, Entity &paddle2, float screenWidth, float screenHeight)
  {
    if (ball.position && ball.velocity && ball.shape)
    {
      // Check collision with top and bottom walls
      if (ball.position->y <= 0 || ball.position->y + ball.shape->height >= screenHeight)
      {
        ball.velocity->vy = -ball.velocity->vy;
      }

      // Check collision with paddles
      checkPaddleCollision(ball, paddle1);
      checkPaddleCollision(ball, paddle2);

      // Check collision with left and right walls (for scoring)
      if (ball.position->x <= 0 || ball.position->x + ball.shape->width > screenWidth)
      {
        // Reset ball position and velocity
        ball.position->x = screenWidth / 2;
        ball.position->y = screenHeight / 2;
        ball.velocity->vx = -ball.velocity->vx;
        ball.velocity->vy = -ball.velocity->vy;
      }
    }
  }

private:
  void checkPaddleCollision(Entity &ball, Entity &paddle)
  {
    if (ball.position && ball.shape && ball.velocity && paddle.position)
    {
      std::shared_ptr<CPosition> paddlePosition = paddle.position;
      std::shared_ptr<CPosition> ballPosition = ball.position;
      int paddleWidth = paddle.shape->width;
      int paddleHeight = paddle.shape->height;
      int ballWidth = ball.shape->width;
      int ballHeight = ball.shape->height;

      if (ballPosition->x + ballWidth - 1 >= paddlePosition->x + 1 &&
          ballPosition->x - 1 <= paddlePosition->x + paddleWidth + 1 &&
          ballPosition->y + ballHeight >= paddlePosition->y &&
          ballPosition->y <= paddlePosition->y + paddleHeight)
      {
        ball.velocity->vx = -ball.velocity->vx;
      }
    }
  }
};

#endif // COLLISION_SYSTEM_H