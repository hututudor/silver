#include <iostream>
#include "Button.h"

Button::Button(Vector2f size, const std::string &str, sf::Font *font, unsigned int characterSize) {
  this->size = size;
  this->rect = new Rect(size);
  this->text = new Text(font, str, characterSize);
}

Button::~Button() {
  delete text;
  delete rect;
}

void Button::onUpdate(const float &dt) {
  this->rect->position = position;
  this->rect->size = size;
  this->text->position = this->rect->position + Vector2f(this->rect->size.x / 2.0f - this->text->getOutBoundsSize().x / 2.0f,
    this->rect->size.y /  2.0f - this->text->getOutBoundsSize().y /1.15f);

  if (this->rect->includes(Mouse::position)) {
    hover = true;

    clicked = Mouse::buttons["left"] != 0;
  } else {
    hover = false;
    clicked = false;
  }

  this->rect->onUpdate(dt);
  this->text->onUpdate(dt);
}

void Button::onRender(sf::RenderWindow *window) {
  this->rect->setColor(hover ? clicked ? clickedBackgroundColor : hoverBackgroundColor : backgroundColor);
  this->text->setColor(hover ? clicked ? clickedTextColor : hoverTextColor : textColor);


  this->rect->onRender(window);
  this->text->onRender(window);
}

bool Button::isClicked() {
  return clicked;
}

bool Button::isHovering() {
  return hover;
}
