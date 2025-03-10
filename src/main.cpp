#include <adal79/engine.h>

int main(int argc, char **argv) {
  adl::engine e;

  // adl::init_cb game_init = []() { return true; };
  adl::update_cb game_update = [](float dt) {};
  // adl::render_cb game_render = []() {};
  // adl::teardown_cb game_teardown = []() {};

  // auto dt = e.deltatime();

  e.on_update(game_update);
  // e.on_render(game_render);
  // e.on_teardown(game_teardown);
  //
  e.run();

  return 0;
}
