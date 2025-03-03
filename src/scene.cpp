#include <SDL3/SDL.h>
#include <cassert>

#include "SDL3/SDL_render.h"

#include "adal79/adal79.h"
#include "adal79/scene.h"

scene::scene(entt::registry &r) : m_registry(r) {}

intro_scene::intro_scene(entt::registry &r) : scene(r) {}

game_scene::game_scene(entt::registry &r) : scene(r) {}

void intro_scene::on_create() {}
void intro_scene::on_teardown() {}

void intro_scene::on_enter() {}
void intro_scene::on_exit() {}

void intro_scene::on_update(float dt) {
  m_last_duration += dt;

  if (m_last_duration >= m_visible_duration) {
    auto sm = m_registry.ctx().get<shared_ptr<s_scene>>();

    assert(m_switch_to_scene_id > 0 && "switch to scene id is not set");
    sm->switch_to(m_switch_to_scene_id);
  }
}

void intro_scene::on_last_update(float dt) {}

void intro_scene::on_render() {
  auto &renderer = m_registry.ctx().get<SDL_Renderer *>();
  assert(renderer != nullptr && "renderer is null");

  SDL_RenderClear(renderer);
  // TODO Render splash screen
  SDL_RenderPresent(renderer);
}

void intro_scene::on_event() {}

void intro_scene::set_switch_to_scene_id(unsigned int id) {
  m_switch_to_scene_id = id;
}

void game_scene::on_create() {}
void game_scene::on_teardown() {}

void game_scene::on_enter() {}
void game_scene::on_exit() {}

void game_scene::on_update(float dt) {}
void game_scene::on_last_update(float dt) {}
void game_scene::on_render() {}
void game_scene::on_event() {}
