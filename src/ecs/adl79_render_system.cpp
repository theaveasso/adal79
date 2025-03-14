#include "adal79/ecs/adl79_render_system.hpp"
#include "adal79/adl79_define.hpp"
#include "adal79/ecs/adl79_component.hpp"

namespace adl
{

render_system::render_system(irenderer& renderer, entt::registry& registry)
	: m_registry(registry)
	, m_renderer(renderer)
{
	adl_debug_constructor(render_system);
};

render_system::~render_system()
{
	adl_debug_deconstructor(render_system);
};

void render_system::draw()
{
	auto view = m_registry.view<sprite_component, transform_component>();
	for (auto [ entity, sprite_comp, transform_comp ] : view.each())
	{

		m_renderer.draw_texture(
			sprite_comp.tex, transform_comp.get_position().x, transform_comp.get_position().y, adl_White);
	}
};

} // namespace adl
