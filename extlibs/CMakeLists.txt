project(extlibs CXX)

include(FetchContent)

add_subdirectory(sdl3 EXCLUDE_FROM_ALL)
add_subdirectory(sdl3_image EXCLUDE_FROM_ALL)
add_subdirectory(sdl3_ttf EXCLUDE_FROM_ALL)
