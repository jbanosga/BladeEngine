cmake_minimum_required(VERSION 3.20)
project(SplitCrit)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# === Find Packages ===
#find_package(Vulkan REQUIRED)
#find_package(glfw3 REQUIRED)
#find_package(glm REQUIRED)

# === ImGui ===
#set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/modules/imgui)
#set(IMGUI_BACKENDS_DIR ${IMGUI_DIR}/backends)

#set(IMGUI_SOURCES
#    ${IMGUI_DIR}/imgui.cpp
#    ${IMGUI_DIR}/imgui_draw.cpp
#    ${IMGUI_DIR}/imgui_tables.cpp
#    ${IMGUI_DIR}/imgui_widgets.cpp
#    ${IMGUI_DIR}/imgui_demo.cpp
#    ${IMGUI_BACKENDS_DIR}/imgui_impl_sdl3.cpp
#    ${IMGUI_BACKENDS_DIR}/imgui_impl_opengl3.cpp
#)

# === Source ===
include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)


# === Create Executable ===
add_executable(${PROJECT_NAME} ${SOURCES})

# === Link ===
#target_link_libraries(${PROJECT_NAME} PRIVATE
#    Vulkan::Vulkan
#    glfw
#    glm::glm
#)

# === Include ===
target_include_directories(${PROJECT_NAME} PRIVATE
    #${IMGUI_DIR}
    #${IMGUI_DIR}/backends
    #${Vulkan_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include
)

# === SDL3 ===
find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

# === OpenGL ===
#find_package(OpenGL REQUIRED)
#target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES} OpenGL::GL)

# === GLM ===
#find_package(glm CONFIG REQUIRED)
#target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)
