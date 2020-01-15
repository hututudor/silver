#include <Main.h>
#include <iostream>

class DefaultScene : public Scene {
private:
  Rect *rect;
  Button *button;

public:
  explicit DefaultScene(GameState gs) : Scene(gs) {
    ResourceManager::loadFont("arial", "../res/fonts/Arial.ttf");
    ResourceManager::loadTexture("player_idle", "../res/textures/player/player_idle.png");

    rect = new Rect(Vector2f(2 * 80, 2 * 110));
    rect->position = Vector2f(100, 0);
    rect->setTexture(ResourceManager::textures["player_idle"]);
    button = new Button(Vector2f(150, 50), "SHOW", ResourceManager::fonts["arial"]);
    button->position = Vector2f(300, 300);
  }

  void onUpdate(const float &dt) override {
    rect->visible = button->isClicked();

    clearGameObjects();
    addGameObject(button);
    addGameObject(rect);
    Scene::onUpdate(dt);
  }
};

int main() {
  Game game(Vector2i(1920, 1080), 8);

  game.addScene("default", new DefaultScene(game.getState()));
  game.setVSync(true);

  game.start("default");
  ResourceManager::free();
}
