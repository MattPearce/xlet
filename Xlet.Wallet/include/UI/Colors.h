#pragma once

#include <stdint.h>

int color565(uint8_t r, uint8_t g, uint8_t b);

namespace Colors
{
    const int Background = color565(0x16, 0x19, 0x25);
    const int Button = color565(0x3A, 0x44, 0x54);
    const int ButtonHighlight = color565(0x81, 0xD2, 0xC7);
    const int Text = color565(0xE0, 0xE0, 0xE0);
    const int TextMenu = color565(0x16, 0x19, 0x25);
    const int TextHighlight = color565(0xE8, 0xC5, 0x47);
}
