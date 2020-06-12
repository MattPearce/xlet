#pragma once

#include "DI/DIContainer.h"

#define DI(TInterface) DIContainer::GetInstance()->Resolve<TInterface>(#TInterface)
#define DITransient(TInterface, TType) DIContainer::GetInstance()->RegisterTransient<TInterface, TType>(#TInterface)
#define DISingleton(TInterface, TType) DIContainer::GetInstance()->RegisterSingleton<TInterface, TType>(#TInterface)
