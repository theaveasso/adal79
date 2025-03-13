#include <cassert>

#include "adal79/core/adl79_engine.hpp"

namespace adl {

engine::engine() : engine(window_config{}) {}

engine::engine(const window_config &conf)
    : m_registry(make_unique<registry>()), m_window(make_unique<window>(conf)),
      m_renderer(make_unique<renderer>(m_window->get(), m_registry->get())),
      m_texture_system(make_unique<texture_manager>(m_renderer->get())) {}

void engine::set_registry(unique_ptr<registry> p_registry) {
  m_registry = std::move(p_registry);
}

bool engine::init() {
  if (m_init_callback) {
    return m_init_callback();
  }

  return false;
}

void engine::run() {
  clock frame_clock;
  clock update_clock;

  float accumalator = 0.0f;

  while (!m_window->window_should_close()) {
    float frame_time = frame_clock.restart();
    accumalator += frame_time;

    m_window->poll_event(m_event);

    while (accumalator >= FRAME_TIME) {
      update(FRAME_TIME);
      accumalator -= FRAME_TIME;
    }

    render();
  }
}

void engine::update(const float dt) {
  if (m_update_callback) {
    m_update_callback(dt);
  }
}

void engine::render() { m_renderer->draw(); }

void engine::set_vsync(const bool vsync) {
  vsync ? m_engine_flag |= vsync_flag : m_engine_flag &= ~vsync_flag;
}

bool engine::is_vsync_enabled() const {
  return (m_engine_flag & vsync_flag) != 0;
}

} // namespace adl
