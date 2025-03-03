#ifndef ADAL79_SYSTEM_H
#define ADAL79_SYSTEM_H

#include <entt.hpp>
#include <memory>
#include <string_view>
#include <unordered_map>
#include <utility>

#include <SDL3/SDL.h>

namespace adl {
class scene;

class system {
public:
  explicit system(entt::registry &r);

  entt::registry &get_registry() { return m_registry; }

protected:
  entt::registry &m_registry;
};

class s_asset final : public system {
public:
  explicit s_asset(entt::registry &r);
  void load_from_rendered_text(std::string_view text, SDL_Color color);
};

class s_component final : public system {
public:
  explicit s_component(entt::registry &r);

  template <typename T, typename... Args>
  void add(entt::entity &e, Args &&...args) {
    m_registry.emplace<T>(e, std::forward<Args>(args)...);
  }

  template <typename T> T &get(entt::entity &e) {
    return m_registry.get<T>(e);
  }

  template <typename T> void remove(entt::entity &e) {
    m_registry.remove<T>(e);
  }

  template <typename T, typename... Args>
  void replace(entt::registry &r, entt::entity &e, Args &&...args) {
    m_registry.replace<T>(e, std::forward<Args>(args)...);
  }
};

class s_scene final : public system {
public:
  explicit s_scene(entt::registry &r);

  void run(float dt);

  unsigned int add(std::shared_ptr<scene> s);
  void remove(unsigned int id);
  void switch_to(unsigned int id);

private:
  unsigned int m_total_scene_count{};

  std::shared_ptr<scene> m_current_scene;
  std::unordered_map<unsigned int, std::shared_ptr<scene>> m_scenes;
};
} // namespace adl

#endif // ADAL79_SYSTEM_H
