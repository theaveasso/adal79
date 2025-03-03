#ifndef ADAL79_REGISTRY_H
#define ADAL79_REGISTRY_H

#include <entt.hpp>

namespace adl {
class registry {
public:
  inline entt::registry &get_registry() { return m_registry; }

  inline entt::entity entity_create() { return m_registry.create(); }

private:
  entt::registry m_registry;
};

} // namespace adl
#endif // ADAL79_REGISTRY_H
