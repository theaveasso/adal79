#ifndef ADAL79_ECS_COMPONENT_H
#define ADAL79_ECS_COMPONENT_H

#include "adal79/graphics/transform.h"
#include <entt.hpp>

namespace adl {

struct c_id {
  std::string name = "default";
  std::string group = "default";
};

struct c_transform {
  transform t;
};

struct c_sprite {
};

} // namespace adl
#endif // ADAL79_ECS_COMPONENT_H
