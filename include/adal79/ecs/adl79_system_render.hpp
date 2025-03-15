#ifndef __ADAL79_ECS_SYSTEM_RENDER_HPP_
#define __ADAL79_ECS_SYSTEM_RENDER_HPP_

#include "adal79/ecs/adl79_component.hpp"
#include "adal79/interface/adl79_irenderer.hpp"

namespace adl
{

class render_system
{
  public:
    explicit render_system(irenderer& renderer, entt::registry& registry);
    ~render_system();

    void draw();

  private:
    entt::registry& m_registry;
    irenderer&      m_renderer;

    std::map<draw_layer, std::shared_ptr<drawable_component>> m_drawables;

  private:
    bool layer_sort(const entt::entity& a, const entt::entity& b);
    void sort();
};

} // namespace adl

#endif // __ADAL79_ECS_SYSTEM_RENDER_HPP_
