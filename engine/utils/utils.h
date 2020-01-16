#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <SFML/Graphics.hpp>

namespace utils {
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
}

#endif