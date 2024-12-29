#include "ButtonManager.h"

ButtonManager::ButtonManager()
{
  register_button(ButtonManager::BUTTON::UP);
  register_button(ButtonManager::BUTTON::DOWN);
  register_button(ButtonManager::BUTTON::LEFT);
  register_button(ButtonManager::BUTTON::RIGHT);
  register_button(ButtonManager::BUTTON::SELECT);
}

bool ButtonManager::is_pressed(const uint& button_pin)
{
  return !gpio_get(button_pin); // Active low
}

void ButtonManager::register_button(const uint& button_pin)
{
  gpio_init(button_pin);
  gpio_set_dir(button_pin, GPIO_IN);
  gpio_pull_up(button_pin);
}