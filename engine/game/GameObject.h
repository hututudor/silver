#pragma once

#include <SFML/Graphics.hpp>
#include "../math/Vector2.h"

class GameObject {
public:
  Vector2f position;
  Vector2f size;
  float rotation;

  bool visible;

  GameObject();
  ~GameObject();

  Vector2f getCenterPosition();

  virtual void onStart();
  virtual void onUpdate(const float &dt);
  virtual void onRender(sf::RenderWindow *window);
  virtual void onDestroy();
};
