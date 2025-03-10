#ifndef ADAL79_ENGINE_H
#define ADAL79_ENGINE_H

#include <functional>

#include <SDL3/SDL.h>

#include "adal79.h"
#include "adal79/graphics/renderer.h"
#include "adal79/window/window.h"
#include "registry.h"

namespace adl {
using init_cb = std::function<bool()>;
using update_cb = std::function<void(float)>;
using render_cb = std::function<void()>;
using teardown_cb = std::function<void()>;

class engine {
public:
  engine();
  explicit engine(const window_config &conf);

public:
  void run();
  inline float deltatime() { return m_deltatime; }

  inline void on_init(init_cb cb) { m_init_callback = cb; }
  inline void on_update(update_cb cb) { m_update_callback = cb; }
  inline void on_render(render_cb cb) { m_render_callback = cb; }
  inline void on_teardown(teardown_cb cb) { m_teardown_callback = cb; }

private:
  init_cb m_init_callback;
  update_cb m_update_callback;
  render_cb m_render_callback;
  teardown_cb m_teardown_callback;

  float m_deltatime{};
  bool m_window_should_close{false};

  SDL_Event m_event;

  unique_ptr<registry> m_registry;

  window m_window;
  renderer m_renderer;

private:
  bool init();
  void update();
  void render();
  void teardown();
};
} // namespace adl

#endif // ADAL79_ENGINE_H
