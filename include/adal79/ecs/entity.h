#ifndef ADAL79_ECS_ENTITY_H
#define ADAL79_ECS_ENTITY_H

#include <entt.hpp>
#include <string_view>
#include <utility>

namespace adl {

class entity {
public:
  explicit entity(entt::registry &p_registry);
  explicit entity(entt::registry &p_registry, std::string_view name,
                  std::string_view group);

  template <typename T, typename... Args> void add(Args &&...args) {
    m_registry.emplace<T>(m_entity, std::forward<Args>(args)...);
  }

  template <typename T> T& get() {
    return m_registry.get<T>(m_entity);
  }

  template <typename T> void remove() { m_registry.remove<T>(); }

private:
  entt::registry &m_registry;
  entt::entity m_entity;
};

} // namespace adl
#endif // ADAL79_ECS_ENTITY_H
