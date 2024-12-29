#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include "ecs/Entity.h"
#include "game/components/CPosition.h"
#include "game/components/CShape.h"
#include "core/display/DisplayManager.h"
#include "ecs/EntityManager.h"

class RenderSystem
{
public:
  RenderSystem(DisplayManager &display, EntityManager &entityManager) : display(display), entityManager(entityManager) {}

  void render()
  {
    display.clearDisplay();

    // Iterate through all entities
    auto &entities = entityManager.getEntities();
    for (const auto &entity : entities)
    {
      if (entity->shape && entity->position)
      {
        auto shape = entity->shape;
        auto position = entity->position;

        if (shape->type == ShapeType::RECTANGLE)
        {
          // Draw the shape using DisplayManager
          display.drawRectangle(position->x, position->y, shape->width, shape->height);
        }

        if (shape->type == ShapeType::CIRCLE)
        {
          // Draw the shape using DisplayManager
          display.drawCircle(position->x, position->y, shape->width / 2);
        }
      }
    }

    // Commit the rendering to the display
    display.update();
  }

private:
  DisplayManager &display;
  EntityManager &entityManager;
};

#endif // RENDER_SYSTEM_H