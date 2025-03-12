#include <cassert>
#include <filesystem>
#include <iostream>

#include <adal79/adal79.h>
#include <adal79/ecs/component.h>
#include <adal79/engine.h>
#include <adal79/graphics/texture.h>

#define CURRENT_DIR std::filesystem::current_path()
#define ASSET_DIR   std::string(CURRENT_DIR) + "/data/assets"

int main(int argc, char **argv) {
  adl::engine e;
  auto       &reg        = e.get_registry();

  adl::init_cb game_init = [&]() {
    auto tm     = e.get_texture_manager();

    auto bg_tex = tm.create(std::string(ASSET_DIR) + "/main_screen.png");
    adl::c_sprite bg(bg_tex);
    bg.set(&adl::c_sprite::dest, SDL_FRect{0, 0, 1280, 720});

    auto player = reg.create_entity();
    player.add<adl::c_id>();
    player.add<adl::c_sprite>(bg);

    auto circle = reg.create_entity();
    circle.add<adl::c_id>("player", "default");
    circle.add<adl::c_circle>();
    circle.add<adl::c_transform>();

    return true;
  };

  adl::update_cb game_update = [&](float dt) {
    auto view = reg.get().view<adl::c_id, adl::c_transform, adl::c_circle>();

    for (auto &v : view) {
      auto &id        = view.get<adl::c_id>(v);
      auto &transform = view.get<adl::c_transform>(v);

      transform.t.translate(adl::vec2f{1280 * 0.5, 720 * 0.5});
      auto &circle = view.get<adl::c_circle>(v);
    }
  };

  e.on_init(game_init);
  e.on_update(game_update);

  e.init();
  e.run();

  return 0;
}
