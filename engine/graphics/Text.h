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
  void setString(const std::string &str);
  void setColor(Color color);

  unsigned int getCharacterSize();
  std::string getString();
  Color getColor();
  Vector2f getOutBoundsPosition();
  Vector2f getOutBoundsSize();

  void onRender(sf::RenderWindow *window) override;
};
