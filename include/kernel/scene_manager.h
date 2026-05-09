#pragma once

#include <atomic>
#include <vector>

namespace Blade
{
    struct EngineState
    {
        bool status;
    };

    class SceneManager
    {
    public:
        SceneManager() = default;
        SceneManager(const SceneManager&) = delete;
        ~SceneManager() = default;

       void SwapBuffers();
       inline const std::vector<EngineState>& GetReadBuffer() const { return buffers_[readIndex_.load()]; }

    private:
        std::vector<EngineState> buffers_[2];
        std::atomic<int> readIndex_{0};
        std::atomic<int> writeIndex_{1};
    };
}
