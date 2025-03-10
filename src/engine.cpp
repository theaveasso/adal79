#include <cassert>
#include <filesystem>

#include "adal79/engine.h"

namespace adl {

engine::engine() : engine(window_config{}) {}

engine::engine(const window_config &conf)
    : m_window(conf), m_renderer(m_window.get_window()) {}

bool engine::init() {
  std::filesystem::current_path("..");

  if (m_init_callback) {
    return m_init_callback();
  }

  return false;
}

void engine::run() {
  while (!m_window.window_should_close()) {
    m_window.poll_event(&m_event);

    update();
    render();
  }
}

void engine::update() {
  if (m_update_callback) {
    m_update_callback(m_deltatime);
  }
}

void engine::render() {
  m_renderer.clear();
  if (m_render_callback) {
    m_render_callback();
    m_renderer.draw();
  }
  m_renderer.preset();
}

// bool engine::on_init() {
//
//   if (!TTF_Init()) {
//     SDL_Log("failed to init TTF_Init: %s", SDL_GetError());
//     return false;
//   }
//
//   m_registry = std::make_unique<registry>();
//
//   m_registry->get_registry().ctx().emplace<SDL_Renderer
//   *>(m_renderer.get()); m_registry->get_registry().ctx().emplace<SDL_Event
//   *>(&m_event);
//
//   auto asset_manager = make_shared<s_asset>(m_registry->get_registry());
//   if (!asset_manager) {
//     SDL_Log("can't create asset_manager");
//   }
//   assert(asset_manager && "failed to create asset manager");
//   m_registry->get_registry().ctx().emplace<shared_ptr<s_asset>>(asset_manager);
//
//   auto component_manager =
//   make_shared<s_component>(m_registry->get_registry());
//   assert(component_manager && "failed to create component manager");
//   m_registry->get_registry().ctx().emplace<shared_ptr<s_component>>(
//       component_manager);
//
//   auto scene_manager = make_shared<s_scene>(m_registry->get_registry());
//   assert(scene_manager && "failed to create scene manager");
//   m_registry->get_registry().ctx().emplace<shared_ptr<s_scene>>(scene_manager);
//
//   return true;
// }

// void engine::run() {
//   // scenes
//   auto intro_s = make_shared<intro_scene>();
//   auto game_s = make_shared<game_scene>();
//
//   auto scene_manager =
//       m_registry->get_registry().ctx().get<shared_ptr<s_scene>>();
//   assert(scene_manager && "failed to create component manager");
//
//   auto asset_manager =
//       m_registry->get_registry().ctx().get<shared_ptr<s_asset>>();
//   assert(asset_manager && "failed to create asset manager");
//
//   auto intro_scene_id = scene_manager->add(intro_s);
//   auto game_scene_id = scene_manager->add(game_s);
//
//   intro_s->set_switch_to_scene_id(game_scene_id);
//
//   scene_manager->switch_to(intro_scene_id);
//
//   double frame_counter = 0;
//   double unprocessed_time = 0;
//   int frames = 0;
//
//   double last_time = SDL_GetTicks();
//   while (!m_window_should_close) {
//     on_event_poll(scene_manager);
//
//     // TODO(xt8o) refactor to clock.reset();
//     double start_time = SDL_GetTicks();
//     double passed_time = start_time - last_time;
//     last_time = start_time;
//
//     unprocessed_time += passed_time;
//     frame_counter += passed_time;
//
//     if (frame_counter >= 1.0) {
//       frames = 0;
//       frame_counter = 0;
//     }
//
//     // refactor to make it more readable
//     bool render = false;
//     while (unprocessed_time > FRAME_TIME) {
//       scene_manager->update(FRAME_TIME);
//       unprocessed_time -= FRAME_TIME;
//       render = true;
//     }
//
//     if (render) {
//       scene_manager->render();
//       frames++;
//     } else {
//       SDL_Delay(1);
//     }
//   }
// }
} // namespace adl
