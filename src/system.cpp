#include <cassert>
#include <utility>

#include <SDL3_image/SDL_image.h>

#include "adal79/scene.h"
#include "adal79/system.h"

namespace adl {
system::system(entt::registry &r) : m_registry(r) {}
s_asset::s_asset(entt::registry &r) : system(r) {}
s_component::s_component(entt::registry &r) : system(r) {}
s_scene::s_scene(entt::registry &r) : system(r) {}

unsigned int s_asset::texture_add(std::string_view path) {
  auto it = m_textures.find(path);
  if (it != m_textures.end()) {
    return it->second.first;
  }

  auto renderer = m_registry.ctx().get<SDL_Renderer *>();
  assert(renderer != nullptr && "renderer is null");

  auto surf = IMG_Load(std::string(path).c_str());
  if (!surf) {
    SDL_LogError(SDL_LOG_CATEGORY_RENDER,
                 "failed to load image from path: %s\n[error]: %s",
                 std::string(path).c_str(), SDL_GetError());
    return -1;
  }

  auto texture = SDL_CreateTextureFromSurface(renderer, surf);
  SDL_DestroySurface(surf);
  if (!texture) {
    SDL_LogError(SDL_LOG_CATEGORY_RENDER,
                 "failed to create texture from surf!\n[error]: %s",
                 SDL_GetError());
    return -1;
  }

  m_textures.insert(
      std::make_pair(path, std::make_pair(m_current_texture_id, texture)));

  return m_current_texture_id++;
}

void s_asset::texture_remove(unsigned int id) {
  for (auto it = m_textures.begin(); it != m_textures.end(); ++it) {
    if (it->second.first == id) {
      m_textures.erase(it->first);
    }
  }
}

SDL_Texture* s_asset::texture_get(unsigned int id) {
  for (auto it = m_textures.begin(); it != m_textures.end(); ++it) {
    if (it->second.first == id) {
      return it->second.second;
    }
  }

  return nullptr;
}

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
