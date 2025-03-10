#ifndef __ADAL79_WINDOW_WINDOW_H_
#define __ADAL79_WINDOW_WINDOW_H_

#include <SDL3/SDL.h>
#include <string>

#include "adal79/adal79.h"

namespace adl {

struct window_config {
  std::string title;
  uint16_t width = 1280;
  uint16_t height = 720;
};

class window {
public:
  window();
  explicit window(const window_config &pconf);

  void poll_event(SDL_Event* event);

  inline bool window_should_close() { return m_window_should_close; }
  inline SDL_Window *get_window() { return m_window.get(); }

private:
  bool m_window_should_close{false};

  window_config m_window_config;
  unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;

private:
  bool init();
};
} // namespace adl

#endif // __ADAL79_WINDOW_WINDOW_H_
