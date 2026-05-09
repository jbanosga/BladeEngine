#pragma once

#include <memory>
namespace Blade {

    class Window;

    class Core
    {
    public:
        Core(Core&) = delete;
        Core& operator=(const Core&) = delete;

        static Core& GetInstance();
        void Initialize();
        void Shutdown();

    private:
        Core() = default;
        ~Core() = default;

        void Run();
        void DoInput();
        void Update(double deltaTime);
        void Render(double alphaTime);


        std::unique_ptr<Blade::Window> pMainWin_;
    };

}
