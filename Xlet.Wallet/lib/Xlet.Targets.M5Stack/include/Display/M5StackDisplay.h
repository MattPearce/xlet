#pragma once

#include <Display/IDisplay.h>

class M5StackDisplay : public IDisplay
{
public:
    void FillScreen(uint32_t color);
    void DrawLine(int32_t x0, int32_t y0, int32_t x1, int32_t y1, uint32_t color);
    void FillRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t r, uint32_t color);
    void DrawRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t r, uint32_t color);
    void DrawString(const char *string, int32_t poX, int32_t poY, uint8_t font, uint16_t color, bool centered = false);
    void DrawBitmap(int16_t x0, int16_t y0, int16_t w, int16_t h, const uint16_t *data);

    int GetWidth();
    int GetHeight();
};
