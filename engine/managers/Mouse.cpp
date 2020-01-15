#include "Mouse.h"

std::map<std::string, int> Mouse::buttons;
Vector2f Mouse::position;

void Mouse::pressButton(const std::string &name) {
  buttons[name]++;
}

void Mouse::releaseButton(const std::string &name) {
  buttons[name] = 0;
}

void Mouse::setPosition(Vector2f pos) {
  position = pos;
}
