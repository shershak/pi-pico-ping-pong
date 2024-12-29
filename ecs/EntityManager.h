#pragma once
#include <stdio.h>
#include <vector>
#include <map>
#include "ecs/Entity.h"

typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map<EntityTag, EntityVec> EntityMap;

class EntityManager
{
private:
  EntityVec m_entities;
  EntityVec m_toAdd;
  EntityMap m_entityMap;
  size_t m_totalEntities = 0;

public:
  EntityManager() {}
  void update();
  std::shared_ptr<Entity> addEntity(const EntityTag &tag);
  EntityVec &getEntities();
  EntityVec &getEntities(const EntityTag &tag);
};