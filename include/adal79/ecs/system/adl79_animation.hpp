#ifndef __ADAL79_ECS_SYSTEM_ADL79_ANIMATION_HPP_
#define __ADAL79_ECS_SYSTEM_ADL79_ANIMATION_HPP_

namespace adl
{
class animation_system
{
  public:
    explicit animation_system(entt::registry& p_registry);
    ~animation_system() { adl_debug_deconstructor(animation_system); }

    void update(float dt);

  private:
    entt::registry& m_registry;
};

} // namespace adl

#endif // __ADAL79_ECS_SYSTEM_ADL79_ANIMATION_HPP_
