#include "adal79/window/adl79_input.hpp"

namespace adl {

void input::update(SDL_Event *p_event) {
  m_last_frame_key = m_this_frame_key;

  auto process_key_down_event = [this](SDL_Event *event, SDL_Keycode sdlkey,
                                       int key) {
    if ((event->type == SDL_EVENT_KEY_DOWN) && (event->key.key == key)) {
      m_this_frame_key |= (1 << key);
    };
  };

  process_key_down_event(p_event, SDLK_UP, static_cast<int>(key::UP));
  process_key_down_event(p_event, SDLK_DOWN, static_cast<int>(key::DOWN));
  process_key_down_event(p_event, SDLK_LEFT, static_cast<int>(key::LEFT));
  process_key_down_event(p_event, SDLK_RIGHT, static_cast<int>(key::RIGHT));
  process_key_down_event(p_event, SDLK_W, static_cast<int>(key::UP));
  process_key_down_event(p_event, SDLK_A, static_cast<int>(key::DOWN));
  process_key_down_event(p_event, SDLK_S, static_cast<int>(key::LEFT));
  process_key_down_event(p_event, SDLK_D, static_cast<int>(key::RIGHT));
}

bool input::is_key_pressed(const int p_key_code) {
  return (m_this_frame_key & (1 << p_key_code)) != 0;
}

bool input::is_key_down(const int p_key_code) {
  bool this_frame = (m_this_frame_key & (1 << p_key_code)) != 0;
  bool last_frame = (m_last_frame_key & (1 << p_key_code)) != 0;

  return this_frame && !last_frame;
}

bool input::is_key_up(const int p_key_code) {
  // this frame key pressed
  bool this_frame = (m_this_frame_key & (1 << p_key_code)) != 0;

  // last frame key pressed
  bool last_frame = (m_last_frame_key & (1 << p_key_code)) != 0;

  return last_frame && !this_frame;
}

} // namespace adl
