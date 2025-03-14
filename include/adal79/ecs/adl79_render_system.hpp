
#ifndef __ADAL79_ECS_RENDER_SYSTEM_H_
#define __ADAL79_ECS_RENDER_SYSTEM_H_

#include "adal79/ecs/adl79_animation_system.hpp"
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
	irenderer& m_renderer;
};

} // namespace adl

#endif // __ADAL79_ECS_RENDER_SYSTEM_H_
