#include "Rect.h"

Rect::Rect(Vector2f size) {
  this->size = size;
}

Rect::~Rect() {
}

void Rect::setColor(Color color) {
  rect.setFillColor(color.toSfColor());
}

void Rect::setTexture(sf::Texture *texture) {
  rect.setTexture(texture);
}

Color Rect::getColor() {
  return Color::fromSfColor(rect.getFillColor());
}

void Rect::onUpdate(const float &dt) {
  rect.setPosition(position.toSfVector());
  rect.setSize(size.toSfVector());
  rect.setRotation(rotation);
}

void Rect::onRender(sf::RenderWindow *window) {
  window->draw(rect);
}

bool Rect::includes(Vector2f point) {
  return point.x > position.x && point.x < position.x + size.x && point.y > position.y && point.y < position.y + size.y;
}
