#include <iostream>
#include "GameObject.h"

GameObject::GameObject() {
  rotation = 0;
}

GameObject::~GameObject() {
}

void GameObject::onStart() {
}

void GameObject::onUpdate(const float& dt) {
}

void GameObject::onRender(sf::RenderWindow *window) {
}

void GameObject::onDestroy() {
}

Vector2f GameObject::getCenterPosition() {
  return Vector2f(position.x + size.x / 2, position.y + size.y / 2);
}
