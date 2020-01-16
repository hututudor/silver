#pragma once

#include <Main.h>

class BackScene : public Scene {
private:
  Text* lines[20];
  Rect* codeContainer;
  Text* codeTitle;
  Rect* currentCode;

  Button* forwardButton;
  Button* backwardsButton;
  Button* resetButton;

  Rect* varContainer;
  Text* varTitle;
  Text* kText;
  Text* vText;

  Rect* solutionsContainer;
  Text* solutionsTitle;
  Text* solutions[6];

  Rect* stackContainer;
  Text* stackTitle;
  Rect* stackLeft;
  Rect* stackRight;
  Rect* stackBottom;
  Rect* stackLineTop;
  Rect* stackLineMiddle;
  Rect* stackLineBottom;

  int currentLine;

  int k = 0;
  int v = 0;
  int x[4];

  bool lastClicked;

public:
  BackScene(GameState gs);

  void onStart() override;
  void onUpdate(const float &dt) override;
  void onRender(sf::RenderWindow *window) override;

  void next();
  void prev();
};
