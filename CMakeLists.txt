cmake_minimum_required(VERSION 3.10)
project(SplitCrit)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "-static")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
add_subdirectory(deps/SDL EXCLUDE_FROM_ALL)

add_executable(SplitCrit ./src/main.cpp)

target_link_libraries(SplitCrit PRIVATE SDL3::SDL3)