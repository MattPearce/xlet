#pragma once

#include "IMenu.h"

class Menu : IMenu
{
public:
    void AddButton(const Image& icon, const std::string& text);

};
