#include "core.h"
#include <SDL3/SDL_render.h>

Core* Core::GetCoreInstance()
{
    if (core_instance_ == nullptr)
    {
        core_instance_ = new Core();
    }

    return core_instance_;
}

void Core::SetRenderer(SDL_Renderer* r)
{
    renderer_ = r;
}

SDL_Renderer* Core::GetRenderer()
{
    return renderer_;
}