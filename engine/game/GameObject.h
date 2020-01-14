#pragma once

#include <SFML/Graphics.hpp>
#include "../math/Vector2.h"

class GameObject {
public:
  Vector2u position;
  Vector2u scale;
  float rotation;

  GameObject();
  ~GameObject();

  virtual void onStart();
  virtual void onUpdate(const float &dt);
  virtual void onRender(sf::RenderWindow *window);
  virtual void onDestroy();
};
