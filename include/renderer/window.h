#pragma once

#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_video.h>
#include <memory>


namespace Blade {

    struct WindowDeleter
    {
        void operator()(struct SDL_Window* w) const { SDL_DestroyWindow(w); }
    };
    using UniqueWindow = std::unique_ptr<struct SDL_Window, WindowDeleter>;

    class Window
    {
    public:

        Window() : width_(600), height_(600) {}
        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;
        ~Window() {}

        bool Initialize();
        bool Shutdown();

    private:
        UniqueWindow windowHandle_;

        int width_;
        int height_;
    };
}
