#include "core.h"

#define LAZY_DELTA_TIME 0.01666

int main()
{
    Blade::Core::GetInstance().Initialize();
    Blade::Core::GetInstance().Shutdown();
    return 0;
}
