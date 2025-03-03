#ifndef ADAL79_ENGINE_H
#define ADAL79_ENGINE_H

#include <memory>
#include <string>

#include <SDL3/SDL.h>
#include <string_view>

#include "registry.h"

class engine {
public:
  engine();
  explicit engine(std::string_view ptitle, uint16_t pwidth, uint16_t pheight);

  void run();

private:
  std::string m_title;
  uint16_t m_width, m_height;

  bool m_window_should_close = false;

  std::unique_ptr<registry> m_registry;

  SDL_Event m_event;
  std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
  std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;

private:
  bool on_init();
  void on_teardown();
};

#endif // ADAL79_ENGINE_H
