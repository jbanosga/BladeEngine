cmake_minimum_required(VERSION 3.20)
project(BladeEngine VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# === Find Packages ===
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
#find_package(glm CONFIG REQUIRED)

# === Source ===
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${SDL2_INCLUDE_DIRS})
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# === Create Executable ===
add_executable(${PROJECT_NAME} ${SOURCES})

# === Link ===
target_link_libraries(${PROJECT_NAME} PRIVATE
    SDL2::SDL2
    OpenGL::GL
    GLEW::GLEW
#    glm::glm
)

# === Include ===
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
