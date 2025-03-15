#include "adal79/ecs/system/adl79_render.hpp"

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

bool render_system::layer_sort(const entt::entity& a, const entt::entity& b)
{
	auto comp_a = m_registry.get<drawable_component>(a);
	auto comp_b = m_registry.get<drawable_component>(b);
	return comp_a.sort_order < comp_b.sort_order;
}

void render_system::sort()
{
}

void render_system::draw()
{
	auto view = m_registry.view<drawable_component>();

	std::vector<entt::entity> sorted_entities(view.begin(), view.end());
	std::sort(sorted_entities.begin(), sorted_entities.end(), [this](const entt::entity& a, const entt::entity& b) {
		auto comp_a = m_registry.get<drawable_component>(a);
		auto comp_b = m_registry.get<drawable_component>(b);

		return comp_a.sort_order < comp_b.sort_order;
	});

	for (auto entity : sorted_entities)
	{
		auto& sprite_comp = m_registry.get<sprite_component>(entity);
	}
};

} // namespace adl
