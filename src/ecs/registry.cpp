#include "adal79/ecs/registry.h"

namespace adl {
entity registry::create_entity() {
  entity e(m_registry);
  return e;
}

entity registry::create_entity(std::string_view p_name,
                               std::string_view p_group) {
  entity e(m_registry, p_name, p_group);
  return e;
}

} // namespace adl
