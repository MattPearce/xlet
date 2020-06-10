#pragma once

#include "DI/DIContainer.h"

#define DI(TInterface) DIContainer::GetInstance()->Resolve<TInterface>()
