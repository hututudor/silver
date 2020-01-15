#pragma once

#include "SFML/Graphics.hpp"

class Color {
public:
  explicit Color(unsigned int r, unsigned int g, unsigned int b, unsigned int a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
  }

  ~Color() {
  }

  sf::Color toSfColor() {
    return sf::Color(r, g, b, a);
  }

  static Color fromSfColor(sf::Color color) {
    return Color(color.r, color.g, color.b, color.a);
  }

  unsigned int r;
  unsigned int g;
  unsigned int b;
  unsigned int a;
};