cmake_minimum_required(VERSION 3.30)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}" CACHE INTERNAL "")

project(adal79 LANGUAGES CXX)

add_subdirectory(extlibs EXCLUDE_FROM_ALL)

if (EMSCRIPTEN)
  set(CMAKE_EXECUTABLE_SUFFIX ".html" CACHE INTERNAL "")
endif()

if (APPLE)
    set(CMAKE_OSX_ARCHITECTURES arm64)
    set(CMAKE_OSX_DEPLOYMENT_TARGET=10.13)
endif()

file(GLOB_RECURSE source_name src/*.cpp)

add_executable("${PROJECT_NAME}" ${source_name})

target_compile_features("${PROJECT_NAME}" PUBLIC cxx_std_23)
target_link_libraries("${PROJECT_NAME}" PRIVATE pthread SDL3::SDL3 SDL3_image::SDL3_image SDL3_ttf::SDL3_ttf fmt)
target_include_directories("${PROJECT_NAME}" PRIVATE include)

target_include_directories("${PROJECT_NAME}" PRIVATE extlibs/entt)

target_precompile_headers("${PROJECT_NAME}" PRIVATE "${CMAKE_SOURCE_DIR}/include/adal79/adl79_pch.hpp")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_compile_definitions(adl_Debug)
  target_compile_options("${PROJECT_NAME}" PRIVATE -g)
endif()

