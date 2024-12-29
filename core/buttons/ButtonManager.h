#ifndef BUTTON_MANAGER_H
#define BUTTON_MANAGER_H

#include "pico/stdlib.h"

class ButtonManager
{
public:
  enum BUTTON {
    UP = 15,
    DOWN = 12,
    LEFT = 13,
    RIGHT = 8,
    SELECT = 14
  };

  ButtonManager();
  bool is_pressed(const uint &button_pin);

private:
  void register_button(const uint &button_pin);
};

#endif // BUTTON_MANAGER_H