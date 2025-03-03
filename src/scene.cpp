#include "adal79/scene.h"

scene::scene(entt::registry &r) : m_registry(r) {}

intro_scene::intro_scene(entt::registry &r) : scene(r) {}

game_scene::game_scene(entt::registry &r) : scene(r) {}

void intro_scene::on_create() {}
void intro_scene::on_teardown() {}

void intro_scene::on_enter() {}
void intro_scene::on_exit() {}

void intro_scene::on_update(float dt) {}
void intro_scene::on_last_update(float dt) {}
void intro_scene::on_render() {}
void intro_scene::on_event() {}

void game_scene::on_create() {}
void game_scene::on_teardown() {}

void game_scene::on_enter() {}
void game_scene::on_exit() {}

void game_scene::on_update(float dt) {}
void game_scene::on_last_update(float dt) {}
void game_scene::on_render() {}
void game_scene::on_event() {}
