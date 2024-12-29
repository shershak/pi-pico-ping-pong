#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include "game/components/CPosition.h"
#include "game/components/CShape.h"
#include "game/components/CVelocity.h"

enum EntityTag
{
  Default,
  Player1Paddle,
  Player2Paddle,
  Ball,
};

class Entity
{
private:
  const size_t m_id = 0;
  const EntityTag m_tag = EntityTag::Default;
  bool m_active = true;

public:
  Entity(const EntityTag &tag, size_t id) : m_id(id), m_tag(tag) {};
  std::shared_ptr<CPosition> position;
  std::shared_ptr<CShape> shape;
  std::shared_ptr<CVelocity> velocity;
  EntityTag tag() const { return m_tag; };
  bool active() const { return m_active; };
  void destroy() { m_active = false; };
};
