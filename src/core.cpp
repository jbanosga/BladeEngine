#include "core.h"
#include "renderer/window.h"

namespace Blade {

    Core& Core::GetInstance()
    {
        static Core instance;
        return instance;
    }

    void Core::Initialize()
    {
        pMainWin_ = std::make_unique<Blade::Window>();
        pMainWin_->Initialize();
    }

    void Core::Shutdown()
    {
        pMainWin_->Shutdown();
    }

}
