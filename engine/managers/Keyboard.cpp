#include "Keyboard.h"

std::map<int, int> Keyboard::keys;

void Keyboard::pressKey(sf::Keyboard::Key key) {
  keys[key]++;
}

void Keyboard::releaseKey(sf::Keyboard::Key key) {
  keys[key] = 0;
}