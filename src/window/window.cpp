#include <cassert>
#include <string>

#include "adal79/window/window.h"

namespace adl {
window::window() : window(window_config{}) {}

window::window(const window_config &pconf)
    : m_window(nullptr, SDL_DestroyWindow) {
  if (!init()) {
    SDL_LogError(1, "failed to initialize engine window: %s", SDL_GetError());
  }
}

bool window::init() {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("failed to init SDL_INIT_VIDEO: %s", SDL_GetError());
    return false;
  };

  m_window.reset(SDL_CreateWindow(m_window_config.title.c_str(),
                                  m_window_config.width, m_window_config.height,
                                  0));
  assert(m_window && "failed to create SDL_Window");
  if (!m_window) {
    SDL_Log("failed to create SDL_Window: %s", SDL_GetError());
    return false;
  }

  return true;
}

void window::poll_event(SDL_Event &event) {
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_EVENT_QUIT:
      m_window_should_close = true;
    default:
      break;
    }
  }
}

} // namespace adl
