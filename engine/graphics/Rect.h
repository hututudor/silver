#pragma once

#include "SFML/Graphics.hpp"
#include "../game/GameObject.h"
#include "../math/Vector2.h"
#include "../math/Color.h"

class Rect : public GameObject {
private:
  sf::RectangleShape rect;

public:
  Rect(Vector2f size);
  ~Rect();

  void setColor(Color color);
  void setTexture(sf::Texture* texture);

  Color getColor();

  bool includes(Vector2f point);

  void onUpdate(const float &dt) override;
  void onRender(sf::RenderWindow *window) override;
};
