#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include "driver/ssd1306.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h"

#define I2C_PORT i2c0
const uint BAUDRATE = 400000;
const uint I2C_SDA = 16;
const uint I2C_SCL = 17;
const uint16_t DISPLAY_ADDRESS = 0x3C;

class DisplayManager
{
public:
  DisplayManager();
  void printText(const char *text);
  void drawRectangle(int16_t x, int16_t y, int16_t width, int16_t height);
  void drawCircle(int16_t x, int16_t y, int16_t radius);
  void clearDisplay();
  void update();

private: 
  pico_ssd1306::SSD1306 display;
};

#endif // DISPLAY_MANAGER_H