#include <iostream>
#include "Text.h"

Text::Text(const sf::Font *font, const std::string &str, unsigned int size) {
  text.setFont(*font);
  setString(str);
  setCharacterSize(size);
}

Text::~Text() {
}

void Text::setCharacterSize(const unsigned int size) {
  text.setCharacterSize(size);
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

unsigned int Text::getCharacterSize() {
  return text.getCharacterSize();
}

std::string Text::getString() {
  return text.getString().toAnsiString();
}

Color Text::getColor() {
  return Color::fromSfColor(text.getFillColor());
}

Vector2f Text::getOutBoundsSize() {
  return Vector2f(text.getLocalBounds().width, text.getGlobalBounds().height);
}

Vector2f Text::getOutBoundsPosition() {
  return Vector2f(text.getLocalBounds().top, text.getGlobalBounds().left);
}

