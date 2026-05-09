#include "kernel/core.h"
#include "kernel/window.h"
#include <chrono>

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

        Run();
    }

    void Core::Shutdown()
    {
        pMainWin_->Shutdown();
    }

    void Core::Run()
    {
        auto previousTime = std::chrono::high_resolution_clock::now();
        double lag = 0.0;
        const double kMsUpdate = 1.0 / 60.0; // 60Hz for logic

        while(pMainWin_->IsRunning())
        {
            auto currenTime = std::chrono::high_resolution_clock::now();
            double elapsed = std::chrono::duration<double>(currenTime - previousTime).count();
            previousTime = currenTime;
            lag += elapsed;

            DoInput();

            while (lag >= kMsUpdate)
            {
                Update(kMsUpdate);
                lag -= kMsUpdate;
            }

            Render(lag / kMsUpdate);
        }
    }

    void Core::DoInput()
    {
        pMainWin_->EventProcess();
    }

    void Core::Update(double deltaTime)
    {
    }

    void Core::Render(double alphaTime)
    {
        pMainWin_->PreRender();
        pMainWin_->Render(alphaTime);
        pMainWin_->PostRender();
    }

}
