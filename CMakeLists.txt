cmake_minimum_required(VERSION 3.10)
project(SplitCrit)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(SplitCrit ./src/main.cpp)