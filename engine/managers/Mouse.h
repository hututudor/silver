#pragma once

#include <map>
#include "../math/Vector2.h"

class Mouse {
public:
  static std::map<std::string, int> buttons;
  static Vector2f position;

  static void setPosition(Vector2f pos);

  static void pressButton(const std::string &name);
  static void releaseButton(const std::string &name);
};
