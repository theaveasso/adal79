#ifndef ADAL79_SYSTEM_INPUT_H
#define ADAL79_SYSTEM_INPUT_H

#include <SDL3/SDL.h>

namespace adl {

class input {
public:
  enum struct key {
    NONE,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ESCAPE,
  };

  void update(SDL_Event *p_event);

  bool is_key_pressed(const int p_key_code);
  bool is_key_down(const int p_key_code);
  bool is_key_up(const int p_key_code);

private:
  uint8_t m_this_frame_key{0};
  uint8_t m_last_frame_key{0};
};

} // namespace adl

#endif // ADAL79_SYSTEM_INPUT_H
