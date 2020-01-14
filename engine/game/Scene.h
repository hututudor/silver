#pragma once

#include <string>
#include <vector>
#include "GameState.h"
#include "GameObject.h"

class Scene {
private:
  std::string *wantsToChangeScene;
  std::vector<GameObject *> gameObjects;

protected:
  void changeState(std::string stateName);
  void addGameObject(GameObject *gameObject);
  void clearGameObjects();

public:
  explicit Scene(GameState &gameState);
  ~Scene();

  virtual void onStart();
  virtual void onUpdate(const float &dt);
  virtual void onRender(sf::RenderWindow *window);
  virtual void onDestroy();
};
