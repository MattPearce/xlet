#pragma once

#include <Input/IInput.h>

class M5StackInput : public IInput
{
public:
    std::list<InputEventType> GetEvents();
};
