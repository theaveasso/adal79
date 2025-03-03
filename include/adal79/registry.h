#ifndef ADAL79_REGISTRY_H
#define ADAL79_REGISTRY_H

#include <entt.hpp>

#include "system.h"

class registry {
public:
  registry() = default;
  ~registry() = default;

  inline entt::registry &get_registry() { return m_registry; }

  inline entt::entity entity_create() { return m_registry.create(); }

  inline s_component &component_system() { return m_component_system; }
  inline s_scene &scene_system() { return m_scene_system; }

private:
  entt::registry m_registry;

  s_component m_component_system;
  s_scene m_scene_system;
};

#endif // ADAL79_REGISTRY_H
