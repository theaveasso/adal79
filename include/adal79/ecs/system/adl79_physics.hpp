#ifndef __ADAL79_ECS_SYSTEM_PHYSICS_HPP_
#define __ADAL79_ECS_SYSTEM_PHYSICS_HPP_

namespace adl
{
class physics_system
{
  public:
	explicit physics_system(entt::registry& registry);
	~physics_system();

	void update(float dt);

  private:
	entt::registry& m_registry;
};
} // namespace adl

#endif // __ADAL79_ECS_SYSTEM_PHYSICS_HPP_
