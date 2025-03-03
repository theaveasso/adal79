project(sdl3_image)

FetchContent_Declare(
  sdl3_image
  GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
  GIT_TAG main
)
FetchContent_MakeAvailable(sdl3_image)
