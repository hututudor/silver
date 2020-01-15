#pragma once

#include "../game/GameObject.h"
#include "../graphics/Text.h"
#include "../graphics/Rect.h"
#include "../math/Vector2.h"
#include "../math/Color.h"
#include "../managers/Mouse.h"

class Button : public GameObject {
private:
  bool hover;
  bool clicked;

public:
  Text *text;
  Rect *rect;

  Color backgroundColor = Color(255, 1, 1, 255);
  Color hoverBackgroundColor = Color(1, 255, 1, 255);
  Color clickedBackgroundColor = Color(1, 1, 255, 255);

  Color textColor = Color(1, 255, 1, 255);
  Color hoverTextColor = Color(1, 1, 255, 255);
  Color clickedTextColor = Color(255, 1, 1, 255);

  Button(Vector2f size, const std::string& str, sf::Font* font, unsigned int characterSize = 20);
  ~Button();

  bool isClicked();
  bool isHovering();

  void onUpdate(const float& dt) override;
  void onRender(sf::RenderWindow *window) override;
};
