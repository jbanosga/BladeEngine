#include "renderer/window.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_video.h>

namespace Blade {

    bool Window::Initialize()
    {
        if (!SDL_Init(SDL_INIT_VIDEO))
            return false;

        SDL_Window* tmpWindow = SDL_CreateWindow("Blade Engine", width_, height_, SDL_WINDOW_OPENGL);
        windowHandle_.reset(SDL_CreateWindow("Blade Engine", width_, height_, SDL_WINDOW_VULKAN));

        return true;
    }

    bool Window::Shutdown()
    {
        SDL_QuitSubSystem(SDL_INIT_VIDEO);

        return true;
    }

}
