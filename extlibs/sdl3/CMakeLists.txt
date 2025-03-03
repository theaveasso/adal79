project(sdl3)

set(SDL_TEST OFF CACHE BOOL "" FORCE)

# Fetch SDL3
FetchContent_Declare(
  sdl3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG main
)
FetchContent_MakeAvailable(sdl3)

