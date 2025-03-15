#ifndef __ADAL79_ECS_COMPONENT_DRAWABLE_HPP_
#define __ADAL79_ECS_COMPONENT_DRAWABLE_HPP_

namespace adl
{
enum struct draw_layer
{
    DEFAULT,
    BACKGROUND,
    FOREGROUND,
    ENTITIES,
};

struct drawable_component
{
    int        sort_order = 0;
    draw_layer layer      = draw_layer::DEFAULT;
};
} // namespace adl

#endif // __ADAL79_ECS_COMPONENT_DRAWABLE_HPP_
