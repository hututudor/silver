#include "BackScene.h"

BackScene::BackScene(GameState gs) : Scene(gs) {
  ResourceManager::loadFont("arial", "../res/fonts/Arial.ttf");
  ResourceManager::loadFont("consolas", "../res/fonts/Consolas.ttf");

  for (int i = 0; i < 20; i++) {
    lines[i] = new Text(ResourceManager::fonts["consolas"], "", 20);
    lines[i]->position = Vector2f(1200, 200 + 30 * i);
  }

  for (int i = 0; i < 6; i++) {
    solutions[i] = new Text(ResourceManager::fonts["consolas"], "", 20);
    solutions[i]->position = Vector2f(825, 370 + 30 * i);
    solutions[i]->setString("as");
  }

  lines[0]->setString("void bkt() {");
  lines[1]->setString("  int k = 1;");
  lines[2]->setString("  x[k] = 1;");
  lines[3]->setString("  while(k > 0) {");
  lines[4]->setString("    int v = 0;");
  lines[5]->setString("    while(x[k] < 3 && v == 0) {");
  lines[6]->setString("    x[k] = x[k] + 1;");
  lines[7]->setString("    if(verif(k))");
  lines[8]->setString("      v = 1;");
  lines[9]->setString("  }");
  lines[10]->setString("  if(v == 0)");
  lines[11]->setString("    k--;");
  lines[12]->setString("  else if(sol(k))");
  lines[13]->setString("    afis(k);");
  lines[14]->setString("  else {");
  lines[15]->setString("    k++;");
  lines[16]->setString("    x[k] = 1;");
  lines[17]->setString("  }");
  lines[18]->setString("}");

  codeContainer = new Rect(Vector2f(550, 590));
  codeContainer->position = Vector2f(1175, 190);
  codeContainer->setColor(Color(0, 0, 0, 100));

  varContainer = new Rect(Vector2f(300, 80));
  varContainer->position = Vector2f(800, 190);
  varContainer->setColor(Color(0, 0, 0, 100));

  solutionsContainer = new Rect(Vector2f(300, 420));
  solutionsContainer->position = Vector2f(800, 360);
  solutionsContainer->setColor(Color(0, 0, 0, 100));

  stackContainer = new Rect(Vector2f(550, 590));
  stackContainer->position = Vector2f(195, 190);
  stackContainer->setColor(Color(0, 0, 0, 100));

  solutionsTitle = new Text(ResourceManager::fonts["arial"], "Solutii", 35);
  solutionsTitle->position = Vector2f(800, 305);
  solutionsTitle->setColor(Color(100, 200, 200, 255));

  currentCode = new Rect(Vector2f(550, 30));
  currentCode->setColor(Color(50, 200, 20, 100));

  codeTitle = new Text(ResourceManager::fonts["arial"], "Algoritm", 35);
  codeTitle->position = Vector2f(1175, 130);
  codeTitle->setColor(Color(100, 200, 200, 255));

  varTitle = new Text(ResourceManager::fonts["arial"], "Variabile", 35);
  varTitle->position = Vector2f(800, 130);
  varTitle->setColor(Color(100, 200, 200, 255));

  stackTitle = new Text(ResourceManager::fonts["arial"], "Stiva", 35);
  stackTitle->position = Vector2f(196, 130);
  stackTitle->setColor(Color(100, 200, 200, 255));

  kText = new Text(ResourceManager::fonts["consolas"], "x: 0", 20);
  kText->position = Vector2f(825, 200);

  vText = new Text(ResourceManager::fonts["consolas"], "v: 0", 20);
  vText->position = Vector2f(825, 230);

  forwardButton = new Button(Vector2f(30, 30), ">", ResourceManager::fonts["arial"], 20);
  forwardButton->position = Vector2f(1210, 790);

  backwardsButton = new Button(Vector2f(30, 30), "<", ResourceManager::fonts["arial"], 20);
  backwardsButton->position = Vector2f(1175, 790);

  resetButton = new Button(Vector2f(80, 30), "Reset", ResourceManager::fonts["arial"], 20);
  resetButton->position = Vector2f(1245, 790);

  forwardButton->backgroundColor = Color(0, 0, 0, 100);
  forwardButton->hoverBackgroundColor = Color(0, 0, 0, 90);
  forwardButton->clickedBackgroundColor = Color(0, 0, 0, 150);
  forwardButton->textColor = Color(255, 255, 255, 255);
  forwardButton->hoverTextColor = Color(255, 255, 255, 255);
  forwardButton->clickedTextColor = Color(255, 255, 255, 255);

  backwardsButton->backgroundColor = Color(0, 0, 0, 100);
  backwardsButton->hoverBackgroundColor = Color(0, 0, 0, 90);
  backwardsButton->clickedBackgroundColor = Color(0, 0, 0, 150);
  backwardsButton->textColor = Color(255, 255, 255, 255);
  backwardsButton->hoverTextColor = Color(255, 255, 255, 255);
  backwardsButton->clickedTextColor = Color(255, 255, 255, 255);

  resetButton->backgroundColor = Color(0, 0, 0, 100);
  resetButton->hoverBackgroundColor = Color(0, 0, 0, 90);
  resetButton->clickedBackgroundColor = Color(0, 0, 0, 150);
  resetButton->textColor = Color(255, 255, 255, 255);
  resetButton->hoverTextColor = Color(255, 255, 255, 255);
  resetButton->clickedTextColor = Color(255, 255, 255, 255);
  resetButton->modifier = 1.15f;

  stackLeft = new Rect(Vector2f(15, 360));
  stackLeft->position = Vector2f(360, 305);

  stackRight = new Rect(Vector2f(15, 360));
  stackRight->position = Vector2f(575, 305);

  stackBottom = new Rect(Vector2f(200, 15));
  stackBottom->position = Vector2f(375, 650);

  stackLineTop = new Rect(Vector2f(200, 15));
  stackLineTop->position = Vector2f(375, 305);

  stackLineBottom = new Rect(Vector2f(200, 15));
  stackLineBottom->position = Vector2f(375, 420);

  stackLineMiddle = new Rect(Vector2f(200, 15));
  stackLineMiddle->position = Vector2f(375, 535);
}

void BackScene::onStart() {
}

void BackScene::onUpdate(const float &dt) {
  vText->setString("v: " + std::to_string(v));
  kText->setString("k: " + std::to_string(k));

  currentCode->position = Vector2f(1175, 200 + 30 * currentLine);

  stackContainer->onUpdate(dt);
  stackTitle->onUpdate(dt);
  stackLeft->onUpdate(dt);
  stackRight->onUpdate(dt);
  stackBottom->onUpdate(dt);
  stackLineTop->onUpdate(dt);
  stackLineMiddle->onUpdate(dt);
  stackLineBottom->onUpdate(dt);

  solutionsContainer->onUpdate(dt);
  solutionsTitle->onUpdate(dt);

  varContainer->onUpdate(dt);
  varTitle->onUpdate(dt);
  kText->onUpdate(dt);
  vText->onUpdate(dt);

  resetButton->onUpdate(dt);
  forwardButton->onUpdate(dt);
  backwardsButton->onUpdate(dt);

  codeTitle->onUpdate(dt);
  codeContainer->onUpdate(dt);
  currentCode->onUpdate(dt);
  for (int i = 0; i < 20; i++) {
    lines[i]->onUpdate(dt);
  }

  for (int i = 0; i < 6; i++) {
    solutions[i]->onUpdate(dt);
  }
}

void BackScene::onRender(sf::RenderWindow *window) {
  window->clear(Color(100, 100, 100, 255).toSfColor());

  stackContainer->onRender(window);
  stackTitle->onRender(window);
  stackLeft->onRender(window);
  stackRight->onRender(window);
  stackBottom->onRender(window);
  stackLineTop->onRender(window);
  stackLineMiddle->onRender(window);
  stackLineBottom->onRender(window);

  solutionsContainer->onRender(window);
  solutionsTitle->onRender(window);

  varContainer->onRender(window);
  varTitle->onRender(window);
  kText->onRender(window);
  vText->onRender(window);

  resetButton->onRender(window);
  forwardButton->onRender(window);
  backwardsButton->onRender(window);

  codeTitle->onRender(window);
  codeContainer->onRender(window);
  currentCode->onRender(window);
  for (int i = 0; i < 19; i++) {
    lines[i]->onRender(window);
  }

  for (int i = 0; i < 6; i++) {
    solutions[i]->onRender(window);
  }

  if (forwardButton->isClicked() && !lastClicked) {
    next();
  }

  if (backwardsButton->isClicked() && !lastClicked) {
    prev();
  }

  lastClicked = Mouse::buttons["left"];
}

void BackScene::next() {
  currentLine++;
  if (currentLine > 18) {
    currentLine = 0;
  }
}

void BackScene::prev() {
  currentLine--;
  if (currentLine < 0) {
    currentLine = 18;
  }
}
