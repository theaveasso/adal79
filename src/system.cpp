#include "adal79/system.h"
#include "adal79/scene.h"
#include <utility>

namespace adl {
system::system(entt::registry &r) : m_registry(r) {}
s_asset::s_asset(entt::registry &r) : system(r) {}
s_component::s_component(entt::registry &r) : system(r) {}
s_scene::s_scene(entt::registry &r) : system(r) {}

void s_scene::run(float dt) {
  if (m_current_scene) {
    m_current_scene->on_event(m_registry);
    m_current_scene->on_update(m_registry, dt);
    m_current_scene->on_render(m_registry);
  }
}

unsigned int s_scene::add(std::shared_ptr<scene> s) {
  auto inserted_scene = m_scenes.insert(std::make_pair(m_total_scene_count, s));
  inserted_scene.first->second->on_create(m_registry);

  return m_total_scene_count++;
}

void s_scene::remove(unsigned int id) {
  auto it = m_scenes.find(id);
  if (it != m_scenes.end()) {
    if (m_current_scene != it->second) {
      m_current_scene->on_exit(m_registry);
    }
    it->second->on_teardown(m_registry);

    m_scenes.erase(it);
  }
}

void s_scene::switch_to(unsigned int id) {
  auto it = m_scenes.find(id);
  if (it != m_scenes.end()) {
    if (m_current_scene) {
      m_current_scene->on_exit(m_registry);
    }
    m_current_scene = it->second;
    m_current_scene->on_enter(m_registry);
  }
}
} // namespace adl
