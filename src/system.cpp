#include "adal79/system.h"
#include "adal79/scene.h"
#include <utility>

s_scene::s_scene() {}

void s_scene::run(float dt) {
  if (m_current_scene) {
    m_current_scene->on_event();
    m_current_scene->on_update(dt);
    m_current_scene->on_render();
  }
}

unsigned int s_scene::add(std::shared_ptr<scene> s) {
  auto inserted_scene = m_scenes.insert(std::make_pair(m_total_scene_count, s));
  inserted_scene.first->second->on_create();

  return m_total_scene_count++;
}

void s_scene::remove(unsigned int id) {
  auto it = m_scenes.find(id);
  if (it != m_scenes.end()) {
    if (m_current_scene != it->second) {
      m_current_scene->on_exit();
    }
    it->second->on_teardown();

    m_scenes.erase(it);
  }
}

void s_scene::switch_to(unsigned int id) {
  auto it = m_scenes.find(id);
  if (it != m_scenes.end()) {
    if (m_current_scene) {
      m_current_scene->on_exit();
    }
    m_current_scene = it->second;
    m_current_scene->on_enter();
  } 
}
