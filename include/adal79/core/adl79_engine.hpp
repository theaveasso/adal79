#ifndef __ADAL79_C0RE_ENGINE_H_
#define __ADAL79_C0RE_ENGINE_H_

#include "adal79/ecs/adl79_registry.hpp"
#include "adal79/ecs/adl79_system.hpp"
#include "adal79/system/adl79_clock.hpp"
#include "adal79/system/adl79_texture_manager_system.hpp"
#include "adal79/window/adl79_window.hpp"

namespace adl
{
using init_cb     = std::function<bool()>;
using update_cb   = std::function<void(float)>;
using render_cb   = std::function<void()>;
using teardown_cb = std::function<void()>;

class engine
{
    int vsync_flag = 1 << 0;

  public:
    engine();

    explicit engine(const window_config& conf);

    ~engine();

  public:
    bool init();
    void run();

    inline void set_target_fps(const float p_fps) { m_target_fps = p_fps; }

    void set_vsync(const bool vsync);
    bool is_vsync_enabled() const;

    inline registry&        get_registry() { return *m_registry; }
    inline irenderer&       get_renderer() { return *m_renderer; }
    inline texture_manager& get_texture_manager() { return *m_texture_manager; }

    inline void on_init(init_cb cb) { m_init_callback = cb; }
    inline void on_update(update_cb cb) { m_update_callback = cb; }
    inline void on_render(render_cb cb) { m_render_callback = cb; }
    inline void on_teardown(teardown_cb cb) { m_teardown_callback = cb; }

  private:
    init_cb     m_init_callback;
    update_cb   m_update_callback;
    render_cb   m_render_callback;
    teardown_cb m_teardown_callback;

    uint16_t m_target_fps{0};
    int      m_engine_flag{0};

    clock m_clock;
    bool  m_window_should_close{false};

    SDL_Event m_event;

    unique_ptr<registry>  m_registry;
    unique_ptr<window>    m_window;
    unique_ptr<irenderer> m_renderer;

    unique_ptr<texture_manager> m_texture_manager;

    shared_ptr<animation_system> m_animation_system = nullptr;
    shared_ptr<render_system>    m_render_system    = nullptr;

  private:
    void update(const float dt);
    void render();
    void teardown();
};
} // namespace adl

#endif // ADAL79_ENGINE_H
