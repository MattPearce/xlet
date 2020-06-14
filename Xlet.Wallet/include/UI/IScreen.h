#pragma once

#include <list>
#include <Input/IInput.h>

class IDisplay;

class IScreen
{
public:
    virtual ~IScreen() {}

    virtual void Update(const std::list<InputEventType>& inputEvents) = 0;

    virtual void Draw(IDisplay* display) = 0;

protected:
    IScreen() {}
};
