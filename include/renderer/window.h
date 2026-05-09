#pragma once

#include <memory>

struct SDL_Window;

namespace Blade {

    struct WindowDeleter { void operator()(SDL_Window* w) const; };
    using UniqueWindow = std::unique_ptr<SDL_Window, WindowDeleter>;

    struct ContextDeleter { void operator()(void* c) const; };
    using UniqueContext = std::unique_ptr<void, ContextDeleter>;

    class Window
    {
    public:

        Window() : width_(640), height_(480) {}
        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;
        ~Window() {}

        void Initialize();
        void Initialize(int w, int h);
        void Shutdown();

        void Render();

        [[nodiscard]] SDL_Window* GetRawWindow() const { return  windowHandle_.get(); }

    private:
        UniqueWindow windowHandle_;
        UniqueContext contextHandle_;

        int width_;
        int height_;
    };
}
