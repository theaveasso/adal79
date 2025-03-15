#ifndef __ADAL79_ECS_COMPONENT_ANIMATION_HPP_
#define __ADAL79_ECS_COMPONENT_ANIMATION_HPP_

namespace adl
{
struct animation_component
{
    animation_component() {}

    float time_elapsed   = 0;
    int   frame_rate     = 0;
    int   current_frame  = 0;
    int   frame_count    = 0;
    int   frames_per_row = 0;
    bool  is_loop        = false;
    bool  is_playing     = false;
};
} // namespace adl

#endif // __ADAL79_ECS_COMPONENT_ANIMATION_HPP_
