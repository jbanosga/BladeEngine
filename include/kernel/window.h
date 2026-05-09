#pragma once

#include <memory>
#include <atomic>

struct SDL_Window;

namespace Blade {

    struct WindowDeleter { void operator()(SDL_Window* w) const; };
    using UniqueWindow = std::unique_ptr<SDL_Window, WindowDeleter>;

    struct ContextDeleter { void operator()(void* c) const; };
    using UniqueContext = std::unique_ptr<void, ContextDeleter>;

    class Window
    {
    public:

        Window() : width_(640), height_(480), isWindowOpen_(true) {}
        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;
        ~Window() {}

        void Initialize();
        void Initialize(int w, int h);
        void Shutdown();

        void EventProcess();
        void PreRender();
        void Render(double alphaTime);
        void PostRender();

        inline bool IsRunning() const { return isWindowOpen_.load(std::memory_order_relaxed); }
        [[nodiscard]] SDL_Window* GetRawWindow() const { return  windowHandle_.get(); }

    private:
        void HandleWindowEvent(const int& key);

        UniqueWindow windowHandle_;
        UniqueContext contextHandle_;

        int width_;
        int height_;
        std::atomic<bool> isWindowOpen_;
    };
}
