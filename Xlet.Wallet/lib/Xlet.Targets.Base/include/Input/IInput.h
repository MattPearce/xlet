#pragma once

#include <list>

enum InputEventType
{
    Up,
    Down,
    Select
};

class IInput
{
public:
    virtual ~IInput() {}

    virtual std::list<InputEventType> GetEvents() = 0;

protected:
    IInput() {}
};
