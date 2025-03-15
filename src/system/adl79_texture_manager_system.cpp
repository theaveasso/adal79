#include <exception>

#include "adal79/system/adl79_texture_manager_system.hpp"

namespace adl
{
texture_manager::texture_manager(irenderer& renderer)
    : m_renderer(renderer)
{
}

result<shared_ptr<texture>> texture_manager::load_asset(std::string_view p_filename)
{
    try
    {
        auto it = m_assets.find(std::string(p_filename));
        if (it != m_assets.end())
        {
            return it->second;
        }

        auto t = make_shared<texture>(m_renderer.get());
        if (!t->load(p_filename))
        {
            return "failed to load texture: " + std::string(p_filename);
        }

        m_assets[std::string(p_filename)] = t;
        return t;
    }
    catch (const std::exception& e)
    {
        return std::string("exception: ") + e.what();
    }
}

void texture_manager::unload_asset(std::string_view p_filename)
{
    auto it = m_assets.find(std::string(p_filename));
    if (it != m_assets.end())
    {
        it->second->unload();
        m_assets.erase(it);
    }
    SDL_Log("texture %s not found", std::string(p_filename).c_str());
}

shared_ptr<texture> texture_manager::create(std::string_view p_filename)
{
    auto tex = load_asset(p_filename);

    auto texture_visitor = [](auto&& arg) {
        if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, shared_ptr<adl::texture>>)
        {
            return arg;
        }
        else
        {
            return shared_ptr<adl::texture>{nullptr};
        }
    };

    return std::visit(texture_visitor, tex);
}

} // namespace adl
