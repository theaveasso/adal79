#include "adal79/ecs/adl79_entity.hpp"

namespace adl {
entity::entity(entt::registry &p_registry)
    : entity(p_registry, "default", "default") {
  m_entity = m_registry.create();
}

entity::entity(entt::registry &p_registry, std::string_view p_name,
               std::string_view p_group)
    : m_registry(p_registry){
  m_entity = m_registry.create();
}

} // namespace adl
