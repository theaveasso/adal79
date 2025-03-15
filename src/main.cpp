#include <cassert>
#include <filesystem>

#include <adal79/adal79.hpp>

#define CURRENT_DIR std::filesystem::current_path()
#define ASSET_DIR std::string(CURRENT_DIR) + "/data/assets"

int main(int argc, char** argv)
{
	adl::engine e;
	auto& reg = e.get_registry();

	adl::init_cb game_init = [&]() {
		auto& tm = e.get_texture_manager();
		auto tex_background = tm.create(std::string(ASSET_DIR) + "/background.png");
		auto tex_ship = tm.create(std::string(ASSET_DIR) + "/spaceships.png");
		auto tex_asteroid = tm.create(std::string(ASSET_DIR) + "/asteroids.png");

		adl::sprite_component sprite_bg;
		sprite_bg.texture = tex_background;
		sprite_bg.dest = SDL_FRect{0, 0, 1280, 720};

		adl::sprite_component sprite_ship;
		sprite_ship.texture = tex_ship;
		sprite_ship.dest = SDL_FRect{0, 0, 1280, 720};

		adl::sprite_component sprite_asteroid;
		sprite_asteroid.texture = tex_asteroid;
		sprite_asteroid.dest = SDL_FRect{0, 0, 1280, 720};

		auto ent_bg = reg.create_entity();
		auto ent_ship = reg.create_entity();
		auto ent_asteroids = reg.create_entity();

		ent_bg.add_component<adl::sprite_component>(sprite_bg);

		ent_ship.add_component<adl::sprite_component>(sprite_ship);

		int asteroids_count = 10;
		for (size_t i = 0; i < asteroids_count; i++)
		{
      auto ent_astroid = reg.create_entity();
      ent_astroid.add_component<adl::sprite_component>(sprite_asteroid);
		}

		return true;
	};

	adl::update_cb game_update = [&](float dt) {};

	e.on_init(game_init);
	e.on_update(game_update);

	e.init();
	e.run();

	return 0;
}
