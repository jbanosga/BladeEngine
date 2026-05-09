#include "core.h"
#include "renderer/window.h"

#define LAZY_DELTA_TIME 0.01666

namespace Blade {

    Core& Core::GetInstance()
    {
        static Core instance;
        return instance;
    }

    void Core::Initialize()
    {
        pMainWin_ = std::make_unique<Blade::Window>();
        pMainWin_->Initialize(1280, 720);
        pMainWin_->Render();
    }

    void Core::Shutdown()
    {
        pMainWin_->Shutdown();
    }

}
