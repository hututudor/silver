#include <Main.h>
#include <iostream>

class DefaultScene : public Scene {
private:
  std::vector<Rect *> rects;

public:
  explicit DefaultScene(GameState gs) : Scene(gs) {
//    ResourceManager::loadFont("arial", "../res/fonts/Arial.ttf");
//    ResourceManager::loadTexture("player_idle", "../res/textures/player/player_idle.png");
  }

  void onStart() override {
    for (int i = 0; i < 1000000; i++) {
      Rect *rect = new Rect(Vector2f(1, 1));
      rects.push_back(rect);
    }
  }

  void onDestroy() override {
    for (auto &it : rects) {
      delete it;
    }
  }

  void onUpdate(const float &dt) override {
    std::cout << "FPS: " << 1 / dt << std::endl;

//    for (auto &it : rects) {
//      it->position = Vector2f(randInt(0, 1920), randInt(0, 1080));
//    }

    clearGameObjects();
    for (auto &it : rects) {
      addGameObject(it);
    }
    Scene::onUpdate(dt);
  }
};

int main() {
  Game game(Vector2i(1920, 1080), 8);

  game.addScene("default", new DefaultScene(game.getState()));

  game.start("default");
  ResourceManager::free();
}
