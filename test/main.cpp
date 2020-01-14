#include <Main.h>
#include <iostream>

class DefaultScene : public Scene {
private:
  Text *text;

public:
  explicit DefaultScene(GameState gs) : Scene(gs) {
    ResourceManager::loadFont("arial", "../res/fonts/Arial.ttf");
    text = new Text(ResourceManager::fonts["arial"], "test", 24);
    text->setColor(Color(0, 255, 0, 255));
  }

  void onUpdate(const float &dt) override {
    float speed = 100;
    text->position = text->position + Vector2u(speed * dt, speed * dt);

    clearGameObjects();
    addGameObject(text);
    Scene::onUpdate(dt);
  }
};

int main() {
  Game game(Vector2i(800, 600));

  game.addScene("default", new DefaultScene(game.getState()));
  game.setVSync(true);

  game.start("default");
}
