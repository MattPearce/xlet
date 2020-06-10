#pragma once

#include <string>

class Image;

class IMenu
{
public:
    void AddButton(const Image& icon, const std::string& text);

    virtual ~IMenu() {}

protected:
    IMenu() {}
};
