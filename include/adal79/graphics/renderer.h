#ifndef __ADAL79_GRAPHICS_RENDERER_H_
#define __ADAL79_GRAPHICS_RENDERER_H_

#include <SDL3/SDL.h>

#include "adal79/adal79.h"

namespace adl {
class renderer {
public:
  explicit renderer(SDL_Window *window);

  void clear();
  void preset();
  void draw();

private:
  SDL_Window *m_window;
  unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;

private:
  bool init();

};
} // namespace adl

#endif // __ADAL79_GRAPHICS_RENDERER_H_
