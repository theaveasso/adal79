#include <memory>

#include <adal79/ecs/component.h>
#include <adal79/engine.h>

int main(int argc, char **argv) {
  adl::engine e;
  unique_ptr<adl::registry> r = make_unique<adl::registry>();

  adl::init_cb game_init = [&]() {
    auto player = r->create_entity();
    player.add_component<adl::c_id>();

    return true;
  };

  adl::update_cb game_update = [&](float dt) {
    auto views = r->get_registry().view<adl::c_id>();
    for (const auto &v : views) {
    }
  };

  e.on_init(game_init);
  e.on_update(game_update);

  e.init();
  e.run();

  return 0;
}
