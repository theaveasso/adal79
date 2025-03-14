#ifndef ADAL79_ECS_REGISTRY_H
#define ADAL79_ECS_REGISTRY_H

#include <entt.hpp>

#include "adal79/ecs/adl79_component.hpp"
#include "adal79/ecs/adl79_entity.hpp"

namespace adl {
class registry {
public:
  registry();
  ~registry();

  inline entt::registry &get() { return m_registry; }

  entity create_entity();
  entity create_entity(const c_id &p_id);
  entity create_entity(std::string_view p_name, std::string_view p_group);

private:
  entt::registry m_registry;
};

} // namespace adl
#endif // ADAL79_ECS_REGISTRY_H
