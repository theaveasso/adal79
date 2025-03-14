#include <cmath>

#include "adal79/ecs/adl79_animation_system.hpp"
#include "adal79/adl79_define.hpp"
#include "adal79/ecs/adl79_component.hpp"

namespace adl
{

animation_system::animation_system(entt::registry& p_registry)
	: m_registry(p_registry)
{
	adl_debug_constructor(animation_system);
}

animation_system::~animation_system()
{
	adl_debug_deconstructor(animation_system);
}

void animation_system::update(float dt)
{
	auto view = m_registry.view<animation_component, sprite_component>();

	for (auto [ entity, animation_comp, sprite_comp ] : view.each())
	{

		float frame_duration = 1.0f / animation_comp.frame_rate;

		if (animation_comp.time_elapsed >= frame_duration)
		{
			int frames_to_advance = static_cast<int>(animation_comp.time_elapsed / frame_duration);

			animation_comp.current_frame += frames_to_advance;

			animation_comp.time_elapsed = fmodf(animation_comp.time_elapsed, frame_duration);

			if (animation_comp.current_frame >= animation_comp.frame_count)
			{
				if (animation_comp.loop)
				{
					animation_comp.current_frame %= animation_comp.frame_count;
				}
				else
				{
					animation_comp.current_frame = animation_comp.current_frame - 1;
					animation_comp.playing = false;
				}
			}
		}

		int frame_width = sprite_comp.src.w;
		int frame_height = sprite_comp.src.h;

		int row = animation_comp.current_frame / animation_comp.frames_per_row;
		int col = animation_comp.current_frame % animation_comp.frames_per_row;

		sprite_comp.src.x = col * frame_width;
		sprite_comp.src.y = row * frame_height;
	}
}

} // namespace adl
