#include "Input/M5StackInput.h"

#include <M5Stack.h>

std::list<InputEventType> M5StackInput::GetEvents()
{
    std::list<InputEventType> events;

    M5.update();

    if(M5.BtnA.wasPressed()) {
        events.push_back(InputEventType::Up);
    }

    if(M5.BtnB.wasPressed()) {
        events.push_back(InputEventType::Select);
    }

    if(M5.BtnC.wasPressed()) {
        events.push_back(InputEventType::Down);
    }

    return events;
}