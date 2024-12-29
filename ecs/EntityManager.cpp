
#include "ecs/EntityManager.h"
#include <algorithm>

std::shared_ptr<Entity> EntityManager::addEntity(const EntityTag &tag)
{
  auto entity = std::shared_ptr<Entity>(new Entity(tag, m_totalEntities++));
  m_toAdd.push_back(entity);
  return entity;
}

void EntityManager::update()
{
  for (auto &entity : m_toAdd)
  {
    m_entities.push_back(entity);
    m_entityMap[entity->tag()].push_back(entity);
  }
  for (auto &entity : m_entities)
  {
    std::remove_if(m_entities.begin(), m_entities.end(), [](std::shared_ptr<Entity> entity) { return !entity->active(); });
    std::remove_if(m_entityMap[entity->tag()].begin(), m_entityMap[entity->tag()].end(), [](std::shared_ptr<Entity> entity) { return !entity->active(); });
  }
  m_toAdd.clear();
}

EntityVec &EntityManager::getEntities()
{
  return m_entities;
}

EntityVec &EntityManager::getEntities(const EntityTag &tag)
{
  return m_entityMap[tag];
}