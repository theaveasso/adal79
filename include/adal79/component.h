#ifndef ADAL79_COMPONENT_H
#define ADAL79_COMPONENT_H

namespace adl {
struct component {};

struct c_texture final : public component {
  unsigned int texture_id;
  int width, height;

  c_texture(unsigned int pid) : texture_id(pid) {};
};
} // namespace adl

#endif // ADAL79_COMPONENT_H
