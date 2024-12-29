#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/pio.h"
#include "core/buttons/ButtonManager.h"
#include "core/display/DisplayManager.h"
#include "ecs/EntityManager.h"
#include "ecs/Entity.h"
#include "game/systems/BallMovementSystem.h"
#include "game/systems/PaddleMovementSystem.h"
#include "game/systems/RenderSystem.h"
#include "game/systems/CollisionSystem.h"

void init_i2c()
{
  i2c_init(I2C_PORT, BAUDRATE);
  gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
  gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
  gpio_pull_up(I2C_SDA);
  gpio_pull_up(I2C_SCL);
}

int main()
{
  stdio_init_all();
  init_i2c();

  ButtonManager buttons;
  DisplayManager display;

  EntityManager entityManager;
  auto paddleLeft = entityManager.addEntity(EntityTag::Player1Paddle);
  paddleLeft->position = std::make_shared<CPosition>(CPosition{0, 0});
  paddleLeft->shape = std::make_shared<CShape>(CShape{2, 10, ShapeType::RECTANGLE});

  auto paddleRight = entityManager.addEntity(EntityTag::Player1Paddle);
  paddleRight->position = std::make_shared<CPosition>(CPosition{125, 0});
  paddleRight->shape = std::make_shared<CShape>(CShape{2, 10, ShapeType::RECTANGLE});

  auto ball = entityManager.addEntity(EntityTag::Ball);
  ball->position = std::make_shared<CPosition>(CPosition{64, 32});
  ball->shape = std::make_shared<CShape>(CShape{5, 5, ShapeType::CIRCLE});
  ball->velocity = std::make_shared<CVelocity>(CVelocity{1, 1});

  BallMovementSystem ballMovementSystem;
  PaddleMovementSystem paddleMovementSystem(buttons);
  RenderSystem renderSystem(display, entityManager);
  CollisionSystem collisionSystem;

  while (true)
  {
    int deltaTime = 1;
    entityManager.update();
    ballMovementSystem.update(*ball, deltaTime);
    paddleMovementSystem.update(*paddleLeft, buttons.UP, buttons.DOWN, deltaTime);
    paddleMovementSystem.update(*paddleRight, buttons.LEFT, buttons.RIGHT, deltaTime);
    collisionSystem.update(*ball, *paddleLeft, *paddleRight, 128, 64);
    renderSystem.render();
  }
}