#include "adal79/core/adl79_sdl_renderer.hpp"

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

bool sdl_renderer::init() {
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

void sdl_renderer::draw_texture(shared_ptr<texture> p_texture, int pos_x, int pos_y, adl_Color tint)
{
	auto texture_size = p_texture->get_size();
	auto dest = SDL_FRect{(float)pos_x, (float)pos_y, (float)texture_size.x, (float)texture_size.y};

	SDL_SetTextureColorMod(p_texture->get(), tint.r, tint.g, tint.b);
	SDL_SetTextureAlphaMod(p_texture->get(), tint.a);
	SDL_RenderTexture(m_renderer.get(), p_texture->get(), nullptr, &dest);
}

void sdl_renderer::draw_texture_v(shared_ptr<texture> p_texture, vec2i position, adl_Color tint)
{
	auto texture_size = p_texture->get_size();
	auto dest = SDL_FRect{(float)position.x, (float)position.y, (float)texture_size.x, (float)texture_size.y};

	SDL_SetTextureColorMod(p_texture->get(), tint.r, tint.g, tint.b);
	SDL_SetTextureAlphaMod(p_texture->get(), tint.a);
	SDL_RenderTexture(m_renderer.get(), p_texture->get(), nullptr, &dest);
}

void sdl_renderer::draw_texture_ex(shared_ptr<texture> p_texture, const SDL_FRect& src, vec2i position, adl_Color tint)
{
	auto texture_size = p_texture->get_size();
	auto dest = SDL_FRect{(float)position.x, (float)position.y, (float)texture_size.x, (float)texture_size.y};

	SDL_SetTextureColorMod(p_texture->get(), tint.r, tint.g, tint.b);
	SDL_SetTextureAlphaMod(p_texture->get(), tint.a);
	SDL_RenderTexture(m_renderer.get(), p_texture->get(), &src, &dest);
}

void sdl_renderer::draw_texture_rec(shared_ptr<texture> p_texture, const SDL_FRect& src, const SDL_FRect& dest,
									vec2i origin, float rot, adl_Color tint)
{
	auto texture_size = p_texture->get_size();

	SDL_SetTextureColorMod(p_texture->get(), tint.r, tint.g, tint.b);
	SDL_SetTextureAlphaMod(p_texture->get(), tint.a);
	// todo how to do
}

} // namespace adl
