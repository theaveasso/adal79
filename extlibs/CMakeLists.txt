project(extlibs CXX)

include(FetchContent)

FetchContent_Declare(
  sdl3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG main
)

FetchContent_GetProperties(sdl3)
if (NOT sdl3_POPULATED)
  set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)

  if ((APPLE AND NOT CMAKE_SYSTEM_NAME MATCHES "Darwin") OR EMSCRIPTEN)
    set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "")
    set(SDL_SHARED OFF)
  else()
    set(SDL_SHARED ON)
  endif()

  FetchContent_MakeAvailable(sdl3)
endif()

