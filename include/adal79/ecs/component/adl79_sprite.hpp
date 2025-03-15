#ifndef __ADAL79_ECS_COMPONENT_SPRITE_HPP_
#define __ADAL79_ECS_COMPONENT_SPRITE_HPP_

#include "adal79/graphic/adl79_texture.hpp"

namespace adl
{
struct sprite_component
{
    sprite_component() {}

    rect  src      = {0, 0};
    rect  dest     = {0, 0};
    float rotation = 0;
    vec2  origin   = {0, 0};

    shared_ptr<texture> texture;
    color               tint;
};

} // namespace adl

#endif // __ADAL79_ECS_COMPONENT_SPRITE_HPP_
