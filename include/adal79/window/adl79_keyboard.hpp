#ifndef __ADAL79_WINDOW_ADL79_KEYBOARD_H_
#define __ADAL79_WINDOW_ADL79_KEYBOARD_H_

#include "adal79/window/adl79_input.hpp"
#include <SDL3/SDL.h>
#include <map>

namespace adl {

class keyboard {
public:
  keyboard();
  ~keyboard() = default;

  void update();

  void on_key_pressed(const int key);
  void on_key_up(const int key);

  const bool is_key_pressed(const int key) const;
  const bool is_key_up(const int key) const;

private:
  std::map<int, input> m_inputs;
};

} // namespace adl

#endif // __ADAL79_WINDOW_ADL79_KEYBOARD_H_
