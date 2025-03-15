#ifndef ADAL79_ECS_REGISTRY_H
#define ADAL79_ECS_REGISTRY_H

#include "adal79/ecs/adl79_entity.hpp"

namespace adl
{
class registry
{
  public:
    registry() { adl_debug_constructor(registry); }
    ~registry() { adl_debug_deconstructor(registry); }

    inline entt::registry& get() { return m_registry; }

    inline entity create_entity() { return entity(m_registry); }
    inline void   destroy_entity(entt::entity& entity) { m_registry.destroy(entity); }

  private:
    entt::registry m_registry;
};
} // namespace adl
#endif // ADAL79_ECS_REGISTRY_H
