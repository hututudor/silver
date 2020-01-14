#include <iostream>
#include "Text.h"

Text::Text(const sf::Font *font, const std::string &str, unsigned int size) {
  text.setFont(*font);
  setString(str);
  setCharacterSize(size);
  setPosition(Vector2u(10, 10));
}

Text::~Text() {
}

void Text::setCharacterSize(const unsigned int size) {
  text.setCharacterSize(size);
}

void Text::setPosition(Vector2u position) {
  text.setPosition(position.x, position.y);
}

void Text::setString(const std::string &str) {
  text.setString(str);
}

void Text::setColor(Color color) {
  text.setFillColor(color.toSfColor());
}

void Text::onRender(sf::RenderWindow *window) {
  text.setPosition(position.x, position.y);
  text.setRotation(rotation);
  window->draw(text);
}
