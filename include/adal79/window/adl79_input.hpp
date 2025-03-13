#ifndef ADAL79_WINDOW_INPUT_H
#define ADAL79_WINDOW_INPUT_H

#include <SDL3/SDL.h>

namespace adl {

struct input {
public:
  void update(bool p_pressed);
  void reset();

  int this_frame;
  int last_frame;
};

} // namespace adl

#endif // ADAL79_SYSTEM_INPUT_H
