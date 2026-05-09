#include "renderer/window.h"
#include "utils/logger.h"

#include <SDL2/SDL.h>
#include <SDL_events.h>
#include <SDL_video.h>
#include <GL/glew.h>

namespace Blade {

    void WindowDeleter::operator()(SDL_Window* w) const
    {
        SDL_DestroyWindow(w);
    }

    void ContextDeleter::operator()(void* c) const
    {
        SDL_GL_DeleteContext(static_cast<SDL_GLContext>(c));
    }

    void Window::Initialize()
    {
        if (!SDL_Init(SDL_INIT_VIDEO))
        {
            BLADE_LOG_ERROR("Could not initialize SDL");
        }

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

        SDL_Window* rawWin = SDL_CreateWindow("Blade Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width_, height_, SDL_WINDOW_OPENGL);
        if (rawWin == nullptr)
        {
            BLADE_LOG_ERROR("Could not create SDL Window");
            throw stderr;
        }
        windowHandle_.reset(rawWin);

        SDL_GLContext rawContext = SDL_GL_CreateContext(windowHandle_.get());
        if (!rawContext)
        {
            BLADE_LOG_ERROR("Could not creat SDL OpenGl Context");
            throw stderr;
        }
        contextHandle_.reset(&rawContext);
    }

    void Window::Initialize(const int w, const int h)
    {
        width_ = w;
        height_ = h;
        Initialize();
    }

    void Window::Shutdown()
    {
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
    }

    void Window::Render()
    {
        bool run = true;
        SDL_Event event;

        while (run) {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                    run = false;
            }

            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            SDL_GL_SwapWindow(windowHandle_.get());
        }
    }
}
