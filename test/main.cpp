#include <Main.h>
#include <iostream>

class DefaultScene : public Scene {
public:
  explicit DefaultScene(GameState gs) : Scene(gs) {}

  void onStart() override {
    std::cout << "fs" << std::endl;
    this->changeState("second");
  }
};

class SecondScene : public Scene {
public:
  explicit SecondScene(GameState gs) : Scene(gs) {}

  void onStart() override {
    std::cout << "ss";
  }
};

int main() {
  Game game;

  game.addScene("default", new DefaultScene(game.getState()));
  game.addScene("second", new SecondScene(game.getState()));
  game.setWindowSize(Vector2u(800, 600));
//  game.setWindowPosition(Vector2i(100, 100));

  game.start("default");
}
