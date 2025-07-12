#include <SDL.h>
#include <SDL_video.h>

#include <iostream>
#include <memory>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main (int argc, char* arg[])
{

    SDL_Window* window = nullptr;
    SDL_Surface* surface = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL ERROR - " << SDL_GetError() << std::endl;
    }
    else 
    {
        window = SDL_CreateWindow("SplitRPG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (!window)
        {
            std::cout << "SDL ERROR - " << SDL_GetError() << std::endl;
        }
        else
        {
            surface = SDL_GetWindowSurface(window);
            SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0, 0, 0));
            SDL_UpdateWindowSurface(window);

            SDL_Event e;
            bool quit = false;

            while (!quit)
            {
                while (SDL_PollEvent(&e))
                {
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                }
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}