#include <cassert>

#include "adal79/graphics/renderer.h"

namespace adl {

renderer::renderer(SDL_Window *window)
    : m_window(window), m_renderer(nullptr, SDL_DestroyRenderer) {
  if (!init()) {
    SDL_LogError(1, "failed to initialize engine renderer: %s", SDL_GetError());

    return;
  }
}

bool renderer::init() {
  m_renderer.reset(SDL_CreateRenderer(m_window, 0));
  assert(m_renderer && "failed to create SDL_Renderer");
  if (!m_renderer) {
    SDL_Log("failed to create SDL_Renderer: %s", SDL_GetError());
    return false;
  }

  SDL_SetRenderVSync(m_renderer.get(), SDL_RENDERER_VSYNC_ADAPTIVE);

  return true;
}

void renderer::clear() { SDL_RenderClear(m_renderer.get()); }

void renderer::preset() { SDL_RenderPresent(m_renderer.get()); }

void renderer::draw() {
  clear();
  preset();
}
} // namespace adl
