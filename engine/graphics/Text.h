#pragma once

#include "SFML/Graphics.hpp"
#include "../game/GameObject.h"
#include "../math/Vector2.h"
#include "../math/Color.h"

class Text : public GameObject {
private:
  sf::Text text;

public:
  Text(const sf::Font *font, const std::string &str, unsigned int size);
  ~Text();

  void setCharacterSize(unsigned int size);
  void setPosition(Vector2u position);
  void setString(const std::string &str);
  void setColor(Color color);

  void onRender(sf::RenderWindow *window) override;
};
