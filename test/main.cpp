#include <Main.h>
#include <iostream>
#include "BackScene.h"

//class DefaultScene : public Scene {
//public:
//  Rect* rect;
//
//  explicit DefaultScene(GameState gs) : Scene(gs) {
//    ResourceManager::loadFont("arial", "../res/fonts/Arial.ttf");
//    ResourceManager::loadTexture("player_idle", "../res/textures/player/player_idle.png");
//
//    rect = new Rect(Vector2f(100, 100));
//    rect->position = Vector2f(100, 100);
//  }
//
//  void onUpdate(const float &dt) override {
//    rect->visible = Keyboard::keys[Key::A] != 0;
//
//    clearGameObjects();
//    addGameObject(rect);
//    Scene::onUpdate(dt);
//  }
//};

int main() {
  Game game(Vector2i(1920, 1080), 8);
  game.addScene("default", new BackScene(game.getState()));
  game.start("default");
  ResourceManager::free();
}
