#ifndef ADAL79_ENGINE_H
#define ADAL79_ENGINE_H

#include <string>

#include <SDL3/SDL.h>
#include <string_view>

#include "adal79.h"
#include "registry.h"
#include "system.h"

namespace adl {
class engine {
public:
  engine();
  explicit engine(std::string_view ptitle, uint16_t pwidth, uint16_t pheight);

  void run();

private:
  std::string m_title;
  uint16_t m_width, m_height;

  bool m_window_should_close = false;
  double m_deltatime{};

  unique_ptr<registry> m_registry;

  SDL_Event m_event;
  unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
  unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;

private:
  bool on_init();
  void on_event_poll(shared_ptr<s_scene> scene_manager);
  void on_teardown();
};
} // namespace adl

#endif // ADAL79_ENGINE_H
