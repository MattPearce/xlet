#include "M5Display.h"

#define ESP32

#include <M5Stack.h>

#include <stdint.h>

void M5Display::FillScreen(uint32_t color)
{
    M5.Lcd.fillScreen(color);
}

void M5Display::DrawLine(int32_t x0, int32_t y0, int32_t x1, int32_t y1, uint32_t color)
{
    M5.Lcd.drawLine(x0, y0, x1, y1, color);
}

void M5Display::FillRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t r, uint32_t color)
{
    M5.Lcd.fillRoundRect(x, y, w, h, r, color);
}

void M5Display::DrawRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t r, uint32_t color)
{
    M5.Lcd.drawRoundRect(x, y, w, h, r, color);
}

void M5Display::DrawString(const char *string, int32_t poX, int32_t poY, uint8_t font)
{
    M5.Lcd.drawString(string, poX, poY, font);
}

void M5Display::DrawBitmap(int16_t x0, int16_t y0, int16_t w, int16_t h, const uint16_t *data)
{
    M5.Lcd.drawBitmap(x0, y0, w, h, data);
}
