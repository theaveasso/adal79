#include "adal79/window/adl79_keyboard.hpp"

namespace adl {
keyboard::keyboard() {}

void keyboard::update() { m_this_frame = m_last_frame; }

const bool keyboard::is_key_pressed(const int key) const {
  return m_this_frame.test(key) && !m_last_frame.test(key);
}

const bool keyboard::is_key_down(const int key) const {
  return m_this_frame.test(key);
}

const bool keyboard::is_key_up(const int key) const {
  return m_last_frame.test(key) && !m_this_frame.test(key);
}

} // namespace adl
