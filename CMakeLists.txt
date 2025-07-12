cmake_minimum_required(VERSION 3.10)
project(SplitCrit)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(SplitCrit ./src/main.cpp)

target_link_libraries(SplitCrit ${SDL2_LIBRARIES})

target_compile_options(SplitCrit PRIVATE ${SDL2_CFLAGS_OTHER})