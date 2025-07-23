#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <vector>

#include "core.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

static SDL_Window* window = nullptr;
static SDL_Renderer* renderer = nullptr;



SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) 
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("GAME", SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer))
    {
        return SDL_APP_FAILURE;
    }
    
    Core::GetCoreInstance()->Initialize();

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) 
{
    if (event->type == SDL_EVENT_QUIT)
    {
        return SDL_APP_SUCCESS;
    }

    Core::GetCoreInstance()->HandleInput(event);

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    // LOGIC LOOP
    Core::GetCoreInstance()->Update();

    // DRAW LOOP
    SDL_SetRenderDrawColor(renderer, 33, 33, 33, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    Core::GetCoreInstance()->Draw(renderer);

    SDL_RenderPresent(renderer);
    
    return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void *appstate, SDL_AppResult result)
{

}