// #include "adal79/window/adl79_input.hpp"
//
// namespace adl {
//
// void input::update(SDL_Event *p_event) {
//   m_last_frame_key            = m_this_frame_key;
//
//   auto process_key_down_event = [this](SDL_Event *event, SDL_Keycode sdlkey,
//                                        int key) {
//     if ((event->type == SDL_EVENT_KEY_DOWN) && (event->key.key == key)) {
//       m_this_frame_key |= (1 << key);
//     };
//   };
//
//   for (auto it = m_inputs.begin(); it != m_inputs.end(); it++) {
//     process_key_down_event(p_event, it->first, static_cast<int>(it->second));
//   }
// }
//
// void input::set(SDL_Keycode p_key_code, int p_key) {
//   m_inputs[p_key_code] = p_key;
// }
//
// bool input::is_key_pressed(const int p_key_code) {
//   return (m_this_frame_key & (1 << p_key_code)) != 0;
// }
//
// bool input::is_key_down(const int p_key_code) {
//   bool this_frame = (m_this_frame_key & (1 << p_key_code)) != 0;
//   bool last_frame = (m_last_frame_key & (1 << p_key_code)) != 0;
//
//   return this_frame && !last_frame;
// }
//
// bool input::is_key_up(const int p_key_code) {
//   // this frame key pressed
//   bool this_frame = (m_this_frame_key & (1 << p_key_code)) != 0;
//
//   // last frame key pressed
//   bool last_frame = (m_last_frame_key & (1 << p_key_code)) != 0;
//
//   return last_frame && !this_frame;
// }
//
// } // namespace adl
