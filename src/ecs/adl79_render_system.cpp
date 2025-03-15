#include "adal79/ecs/system/adl79_render.hpp"
#include "fmt/base.h"

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

void render_system::draw()
{
    auto view = m_registry.view<id_component, drawable_component>();

    std::vector<entt::entity> sorted_entities(view.begin(), view.end());
    std::sort(sorted_entities.begin(), sorted_entities.end(), [this](const entt::entity& a, const entt::entity& b) {
        auto comp_a = m_registry.get<drawable_component>(a);
        auto comp_b = m_registry.get<drawable_component>(b);

        return comp_a.sort_order < comp_b.sort_order;
    });

    int size_of_tile = 0;
    for (auto entity : sorted_entities)
    {
        auto d  = m_registry.get<drawable_component>(entity);
        auto id = m_registry.get<id_component>(entity);

        if (id.group == "solid_tile")
        {
            m_renderer.draw_rectangle_rec(d.rect, color{10, 255, 255, 255});
            m_renderer.draw_rectangle_lines_ex(d.rect, 1, color{0, 0, 0, 255});
        }
    }
    fmt::println("size of tile {}", size_of_tile);
};

} // namespace adl
