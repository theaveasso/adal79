#include <cassert>
#include <filesystem>

#include <adal79/adal79.hpp>

#define CURRENT_DIR std::filesystem::current_path()
#define ASSET_DIR std::string(CURRENT_DIR) + "/data/assets"

int main(int argc, char** argv)
{
	adl::engine e;
	auto& reg = e.get_registry();

	adl::init_cb game_init = [ & ]() {
		auto& tm = e.get_texture_manager();
		auto bg_tex = tm.create(std::string(ASSET_DIR) + "/main_screen.png");

		adl::sprite_component bg;
		bg.tex = bg_tex;
		bg.dest = SDL_FRect{0, 0, 1280, 720};

		auto bg_ent = reg.create_entity();
		bg_ent.add<adl::sprite_component>(bg);
		bg_ent.add<adl::transform_component>();

		return true;
	};

	// constexpr float gravity       = -9.8f;
	// constexpr float bounce_factor = 0.8f;

	adl::update_cb game_update = [ & ](float dt) {};

	e.on_init(game_init);
	e.on_update(game_update);

	e.init();
	e.run();

	return 0;
}
