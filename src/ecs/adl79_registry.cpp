#include "adal79/ecs/adl79_registry.hpp"

namespace adl {
entity registry::create_entity() { return entity(m_registry); }

entity registry::create_entity(std::string_view p_name,
                               std::string_view p_group) {
  return entity(m_registry, p_name, p_group);
}

} // namespace adl
