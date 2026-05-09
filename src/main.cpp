#include "kernel/core.h"

int main()
{
    Blade::Core::GetInstance().Initialize();
    Blade::Core::GetInstance().Shutdown();
    return 0;
}
