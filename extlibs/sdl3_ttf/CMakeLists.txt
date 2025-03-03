project(sdl3_ttf)

FetchContent_Declare(
  sdl3_ttf
  GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
  GIT_TAG main
)
FetchContent_MakeAvailable(sdl3_ttf)
