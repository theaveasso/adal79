#include <cassert>

#include "adal79/core/adl79_engine.hpp"
#include "adal79/ecs/adl79_system.hpp"
#include "adal79/adl79_define.hpp"
#include "adal79/core/adl79_sdl_renderer.hpp"

namespace adl
{

engine::engine()
	: engine(window_config{})
{
}

engine::engine(const window_config& conf)
	: m_registry(make_unique<registry>())
	, m_window(make_unique<window>(conf))
	, m_renderer(make_unique<sdl_renderer>(m_window->get()))
	, m_texture_manager(make_unique<texture_manager>(*m_renderer))
	, m_animation_system(make_shared<animation_system>(m_registry->get()))
	, m_render_system(make_shared<render_system>(*m_renderer, m_registry->get()))
{
	adl_debug_constructor(engine);
}

engine::~engine()
{
	adl_debug_deconstructor(engine)
}

bool engine::init()
{
	if (m_init_callback)
	{
		m_init_callback();
	}

	return true;
}

void engine::run()
{
	clock frame_clock;
	clock update_clock;

	float accumalator = 0.0f;

	while (!m_window->window_should_close())
	{
		float frame_time = frame_clock.restart();
		accumalator += frame_time;

		m_window->poll_event(m_event);

		while (accumalator >= FRAME_TIME)
		{
			update(FRAME_TIME);
			accumalator -= FRAME_TIME;
		}

		render();
	}
}

void engine::update(const float dt)
{
	if (m_update_callback)
	{
		m_update_callback(dt);
	}

	m_animation_system->update(dt);
}

void engine::render()
{
	m_renderer->begin_frame();
	m_render_system->draw();
	m_renderer->end_frame();
}

void engine::set_vsync(const bool vsync)
{
	vsync ? m_engine_flag |= vsync_flag : m_engine_flag &= ~vsync_flag;
}

bool engine::is_vsync_enabled() const
{
	return (m_engine_flag & vsync_flag) != 0;
}

} // namespace adl
