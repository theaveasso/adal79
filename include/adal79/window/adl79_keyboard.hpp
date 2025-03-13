#ifndef __ADAL79_WINDOW_ADL79_KEYBOARD_H_
#define __ADAL79_WINDOW_ADL79_KEYBOARD_H_

#include <bitset>

#include <SDL3/SDL.h>

#include "adal79/adl79_define.hpp"

namespace adl {

class keyboard {
public:
  keyboard();
  ~keyboard() = default;

  void update();

  const bool is_key_pressed(const int key) const;
  const bool is_key_down(const int key) const;
  const bool is_key_up(const int key) const;

private:
  std::bitset<adl_KEY_COUNT> m_this_frame;
  std::bitset<adl_KEY_COUNT> m_last_frame;
};

} // namespace adl

#endif // __ADAL79_WINDOW_ADL79_KEYBOARD_H_
