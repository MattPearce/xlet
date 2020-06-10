#include "../../DI.h"
#include "../../Display/IDisplay.h"
#include "Display/M5Display.h"

void InitTarget()
{
    auto di = DIContainer::GetInstance();

    di->RegisterSingleton<IDisplay, M5Display>();
}
