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
    circle.add<adl::c_velocity>();

    return true;
  };

  constexpr float gravity       = -9.8f;
  constexpr float bounce_factor = 0.8f;

  adl::update_cb game_update    = [&](float dt) {
    auto view =
        reg.get().view<adl::c_transform, adl::c_circle, adl::c_velocity>();

    for (auto &v : view) {
      auto &transform = view.get<adl::c_transform>(v);
      auto &circle    = view.get<adl::c_circle>(v);
      auto &[velocity]     = view.get<adl::c_velocity>(v);

      velocity = {250, 250};
      circle.radius   = 50;

      // Apply gravity
      // velocity.y += gravity * dt;

      // Update position
      auto pos = transform.get_position();
      pos.x += velocity.x * dt;
      pos.y += velocity.y * dt;

      // Handle collisions
      if (pos.y + circle.radius >= 720) {
        pos.y = 720 - circle.radius;
        velocity.y *= -bounce_factor;
      }
      if (pos.y - circle.radius <= 0) {
        pos.y = circle.radius;
        velocity.y *= -bounce_factor;
      }
      if (pos.x + circle.radius >= 1280) {
        pos.x = 1280 - circle.radius;
        velocity.x *= -bounce_factor;
      }
      if (pos.x - circle.radius <= 0) {
        pos.x = circle.radius;
        velocity.x *= -bounce_factor;
      }

      // Update transform
      transform.set_position(pos);
      std::cout << "pos " << pos.x << ", " << pos.y << "\n";
    }
  };

  e.on_init(game_init);
  e.on_update(game_update);

  e.init();
  e.run();

  return 0;
}
