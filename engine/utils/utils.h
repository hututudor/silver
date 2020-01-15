#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>

void sleep(int milliseconds) {
  sf::sleep(sf::milliseconds(milliseconds));
}

int randInt(int left, int right) {
  return rand() % (right - left) + left;
}

int getElapsedTime() {
  static sf::Clock clock;
  return clock.getElapsedTime().asMilliseconds();
}