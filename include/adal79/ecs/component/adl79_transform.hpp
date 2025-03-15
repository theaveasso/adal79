#ifndef __ADAL79_ECS_COMPONENT_TRANSFORM_HPP_
#define __ADAL79_ECS_COMPONENT_TRANSFORM_HPP_

namespace adl
{
struct transform_component
{
    bool is_static = true;

    vec2 position      = {0, 0};
    vec2 prev_position = {0, 0};
};
} // namespace adl

#endif // __ADAL79_ECS_COMPONENT_KEYBOARD_MOVEMENT_HPP_
