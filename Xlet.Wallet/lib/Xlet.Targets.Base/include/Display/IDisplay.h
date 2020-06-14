#pragma once

#include <stdint.h>

class IDisplay
{
public:
    virtual ~IDisplay() {}

    virtual void FillScreen(uint32_t color) = 0;
    virtual void DrawLine(int32_t x0, int32_t y0, int32_t x1, int32_t y1, uint32_t color) = 0;
    virtual void FillRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t r, uint32_t color) = 0;
    virtual void DrawRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t r, uint32_t color) = 0;
    virtual void DrawString(const char *string, int32_t poX, int32_t poY, uint8_t font, uint16_t color, bool centered = false) = 0;
    virtual void DrawBitmap(int16_t x0, int16_t y0, int16_t w, int16_t h, const uint16_t *data) = 0;

    virtual int GetWidth() = 0;
    virtual int GetHeight() = 0;

protected:
    IDisplay() {}
};
