#include "DisplayManager.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "core/display/driver/textRenderer/TextRenderer.h"
#include "core/display/driver/shapeRenderer/ShapeRenderer.h"

DisplayManager::DisplayManager() : display(I2C_PORT, DISPLAY_ADDRESS, pico_ssd1306::Size::W128xH64)
{
  display.setOrientation(0);
}

void DisplayManager::printText(const char *text)
{
  pico_ssd1306::drawText(&display, font_5x8, text, 0, 0);
  display.sendBuffer();
};

void DisplayManager::drawRectangle(int16_t x, int16_t y, int16_t width, int16_t height)
{
  pico_ssd1306::fillRect(&display, x, y, x + width, y + height);
};

void DisplayManager::drawCircle(int16_t x, int16_t y, int16_t radius)
{
  pico_ssd1306::fillCircle(&display, x, y, radius);
};

void DisplayManager::clearDisplay()
{
  pico_ssd1306::fillRect(&display, 0, 0, 128, 64, pico_ssd1306::WriteMode::SUBTRACT);
};

void DisplayManager::update() { display.sendBuffer(); };