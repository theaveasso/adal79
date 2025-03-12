#include <adal79/engine.h>
#include <cassert>
#include <filesystem>

#include <adal79/adal79.h>
#include <adal79/engine.h>
#include <adal79/graphics/texture.h>


#define CURRENT_DIR std::filesystem::current_path()
#define ASSET_DIR std::string(CURRENT_DIR) + "/data/assets"

int main(int argc, char **argv) {
  adl::engine e;
  auto& reg = e.get_registry();

  adl::init_cb game_init = [&]() {
    auto tm = e.get_texture_manager();

    auto bg_tex = tm.create(std::string(ASSET_DIR) + "/main_screen.png");
    adl::c_sprite bg(bg_tex);
    bg.set(&adl::c_sprite::dest, SDL_FRect{0, 0, 1280, 720});

    auto player = e.get_registry().create_entity();
    player.add_component<adl::c_id>();
    player.add_component<adl::c_sprite>(bg);

    return true;
  };

  adl::update_cb game_update = [&](float dt) {
  };

  e.on_init(game_init);
  e.on_update(game_update);

  e.init();
  e.run();

  return 0;
}
