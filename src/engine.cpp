#include "adal79/engine.h"

#include "SDL3/SDL_events.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_log.h"

#include "adal79/scene.h"
#include <cassert>

engine::engine() : engine("default", 1280, 720) {}

engine::engine(std::string_view ptitle, uint16_t pwidth, uint16_t pheight)
    : m_title(ptitle), m_width(pwidth), m_height(pheight), m_registry(nullptr),
      m_window(nullptr, SDL_DestroyWindow),
      m_renderer(nullptr, SDL_DestroyRenderer) {
  if (!on_init()) {
    SDL_Log("failed to initialize the engine");
    return;
  }
}

bool engine::on_init() {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("failed to init SDL_INIT_VIDEO: %s", SDL_GetError());
    return false;
  };

  m_window.reset(SDL_CreateWindow(m_title.c_str(), m_width, m_height, 0));
  if (m_window.get() == nullptr) {
    SDL_Log("failed to create SDL_Window: %s", SDL_GetError());
    return false;
  }

  m_renderer.reset(SDL_CreateRenderer(m_window.get(), 0));
  if (m_renderer.get() == nullptr) {
    SDL_Log("failed to create SDL_Renderer: %s", SDL_GetError());
    return false;
  }
  SDL_SetRenderVSync(m_renderer.get(), -1);

  m_registry = std::make_unique<registry>();

  SDL_LogInfo(0, "successfully initialze engine core;");

  m_registry->get_registry().ctx().emplace<SDL_Renderer *>(m_renderer.get());

  return true;
}

void engine::run() {
  // scenes
  auto intro_s = make_shared<intro_scene>(m_registry->get_registry());
  auto game_s = make_shared<game_scene>(m_registry->get_registry());

  // systems
  auto scene_manager = make_shared<s_scene>();
  assert(scene_manager != nullptr && "failed to create scene manager");
  m_registry->get_registry().ctx().emplace<shared_ptr<s_scene>>(scene_manager);

  auto intro_scene_id = scene_manager->add(intro_s);
  auto game_scene_id = scene_manager->add(game_s);

  intro_s->set_switch_to_scene_id(game_scene_id);

  scene_manager->switch_to(intro_scene_id);

  while (!m_window_should_close) {
    while (SDL_PollEvent(&m_event)) {
      switch (m_event.type) {
      case SDL_EVENT_QUIT:
        m_window_should_close = true;
      default:
        break;
      }
    }

    scene_manager->run(2.0);
  }

  on_teardown();
}

void engine::on_teardown() { SDL_Quit(); }
