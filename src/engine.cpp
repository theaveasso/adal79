#include <cassert>

#include "adal79/engine.h"

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
  m_clock.restart();

  while (!m_window->window_should_close()) {
    m_deltatime = m_clock.get_elapsed_time();
    m_window->poll_event(m_event);

    update();
    render();
  }
}

void engine::update() {
  if (m_update_callback) {
    m_update_callback(m_deltatime);
  }
}

void engine::render() {
  m_renderer->draw();
}
} // namespace adl
