#pragma once

#include <functional>

struct DIRegistered
{
    std::function<void*> Factory;

    bool GiveOwnership;
};
