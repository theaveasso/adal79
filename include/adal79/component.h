#ifndef ADAL79_COMPONENT_H
#define ADAL79_COMPONENT_H

namespace adl {
struct component {};

struct c_texture final : public component {
  float a;
  c_texture(float pa) : a(pa) {};
};
} // namespace adl

#endif // ADAL79_COMPONENT_H
