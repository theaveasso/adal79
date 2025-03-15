#include <fmt/format.h>

#include "adal79/ecs/component/adl79_drawable.hpp"
#include "adal79/ecs/component/adl79_id.hpp"
#include "adal79/system/adl79_level_parser.hpp"

namespace adl
{
level_parser::level_parser(registry& registry, shared_ptr<file_handler> handler)
    : m_registry(registry)
    , m_handler(handler)
{
    adl_debug_constructor(level_parser);
}

level_parser::~level_parser()
{
    adl_debug_deconstructor(level_parser);
}

void level_parser::parse()
{
    auto lines = m_handler->read_lines();

    float x = 0, y = 0;

    for (const auto& line : lines)
    {
        for (const auto ch : line)
        {
            switch (ch)
            {
            case '#': {
                id_component       id;
                drawable_component drawable;

                id.group       = "solid_tile";
                drawable.layer = draw_layer::BACKGROUND;
                drawable.rect  = {x, y, static_cast<float>(m_tile_size), static_cast<float>(m_tile_size)};

                auto solid_tile = m_registry.create_entity();
                solid_tile.add_component<id_component>(id);
                solid_tile.add_component<drawable_component>(drawable);

                break;
            }
            case ' ': {
                break;
            }
            case 'X': {
                break;
            }
            default: break;
            }
            x += m_tile_size;
        }
        y += m_tile_size;
        x = 0;
    }
}
} // namespace adl
