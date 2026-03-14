cmake_minimum_required(VERSION 3.30)

project(Platformer
        VERSION 0.1.0
        DESCRIPTION "A platformer game made with SDL3"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED 23)

set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

# Disable Shared Libs
set(BUILD_SHARED_LIBS OFF)
set(SDL_SHARED OFF)
set(SDL_STATIC ON)

# Fetch code for dependencies : SDL3
include(FetchContent)
FetchContent_Declare(
  SDL3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG release-3.4.2
)
FetchContent_MakeAvailable(SDL3)

add_executable(platformer_sdl)

target_sources(platformer_sdl PRIVATE
  src/main.cpp
  src/init.hpp
  src/init.cpp
)
target_link_libraries(platformer_sdl PRIVATE SDL3::SDL3)
