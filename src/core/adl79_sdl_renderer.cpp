#include "adal79/core/adl79_sdl_renderer.hpp"
#include "SDL3/SDL_render.h"

namespace adl
{

sdl_renderer::sdl_renderer(SDL_Window& window)
    : m_window(window)
    , m_renderer(nullptr, &SDL_DestroyRenderer)
{
    adl_debug_constructor(sdl_renderer);
    if (!init())
    {
        SDL_LogError(SDL_LOG_PRIORITY_ERROR, "failed to initialize engine renderer: %s", SDL_GetError());
    }
}

sdl_renderer::~sdl_renderer()
{
    adl_debug_deconstructor(sdl_renderer)
}

bool sdl_renderer::init()
{
    m_renderer.reset(SDL_CreateRenderer(&m_window, 0));
    assert(m_renderer && "failed to create SDL_Renderer");
    if (!m_renderer)
    {
        SDL_Log("failed to create SDL_Renderer: %s", SDL_GetError());
        return false;
    }

    return true;
}

void sdl_renderer::begin_frame()
{
    SDL_RenderClear(m_renderer.get());
    SDL_SetRenderDrawColor(m_renderer.get(), 255, 255, 255, 255);
}

void sdl_renderer::end_frame()
{
    SDL_RenderPresent(m_renderer.get());
}

void sdl_renderer::draw_texture(const shared_ptr<texture>& texture, int posX, int posY, color tint)
{
}

void sdl_renderer::draw_texture_v(const shared_ptr<texture>& texture, vec2 position, color tint)
{
}

void sdl_renderer::draw_texture_ex(const shared_ptr<texture>& texture, vec2 position, float rotation, float scale, color tint)
{
}

void sdl_renderer::draw_texture_rec(const shared_ptr<texture>& texture, rect source, vec2 position, color tint)
{
}

void sdl_renderer::draw_texture_pro(const shared_ptr<texture>& texture, rect source, rect dest, vec2 origin, float rotation, color tint)
{
}

} // namespace adl
