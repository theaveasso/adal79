#include <SDL3/SDL.h>
#include <cassert>

#include "SDL3/SDL_render.h"

#include "adal79/adal79.h"
#include "adal79/scene.h"
#include "adal79/component.h"
#include "adal79/system.h"

namespace adl {
void intro_scene::on_create(entt::registry &r) {
  auto component_manager = r.ctx().get<shared_ptr<s_component>>();
  assert(component_manager && "failed to create component manager");

  auto asset_manager = r.ctx().get<shared_ptr<s_asset>>();
  assert(asset_manager && "failed to create asset manager");

  auto e_background = r.create();
  component_manager->add<c_texture>(e_background, 10);
}
void intro_scene::on_teardown(entt::registry &r) {}

void intro_scene::on_enter(entt::registry &r) {}
void intro_scene::on_exit(entt::registry &r) {}

void intro_scene::on_update(entt::registry &r, float dt) {
  m_last_duration += dt;

  if (m_last_duration >= m_visible_duration) {
    auto sm = r.ctx().get<shared_ptr<s_scene>>();

    assert(m_switch_to_scene_id > 0 && "switch to scene id is not set");
    sm->switch_to(m_switch_to_scene_id);
  }
}

void intro_scene::on_last_update(entt::registry &r, float dt) {}

void intro_scene::on_render(entt::registry &r) {
  auto &renderer = r.ctx().get<SDL_Renderer *>();
  assert(renderer != nullptr && "renderer is null");

  SDL_RenderClear(renderer);
  // TODO Render splash screen
  SDL_RenderPresent(renderer);
}

void intro_scene::on_event(entt::registry &r) {}

void intro_scene::set_switch_to_scene_id(unsigned int id) {
  m_switch_to_scene_id = id;
}

void game_scene::on_create(entt::registry &r) {}
void game_scene::on_teardown(entt::registry &r) {}

void game_scene::on_enter(entt::registry &r) {}
void game_scene::on_exit(entt::registry &r) {}

void game_scene::on_update(entt::registry &r, float dt) {}
void game_scene::on_last_update(entt::registry &r, float dt) {}
void game_scene::on_render(entt::registry &r) {}
void game_scene::on_event(entt::registry &r) {}

} // namespace adl
