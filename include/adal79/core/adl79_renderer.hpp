#ifndef __ADAL79_CORE_RENDERER_H_
#define __ADAL79_CORE_RENDERER_H_

#include <SDL3/SDL.h>
#include <entt.hpp>

#include "adal79/adl79_define.hpp"

namespace adl {

class renderer {
public:
  explicit renderer(SDL_Window &p_window, entt::registry &p_registry);
  ~renderer() = default;

  inline void clear() { SDL_RenderClear(m_renderer.get()); }
  inline void preset() { SDL_RenderPresent(m_renderer.get()); }

  void draw();

  SDL_Renderer &get() { return *m_renderer; }

private:
  SDL_Window     &m_window;
  entt::registry &m_registry;

  unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;

private:
  bool init();
};

} // namespace adl

#endif // __ADAL79_GRAPHICS_RENDERER_H_
