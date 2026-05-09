#include "kernel/scene_manager.h"

namespace Blade
{
    void SceneManager::SwapBuffers()
    {
        readIndex_.store(writeIndex_.exchange(readIndex_.load()));
    }
}
