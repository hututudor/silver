#pragma once

#include <string>
#include <map>
#include "GameState.h"
#include "GameObject.h"

class Scene {
private:
  std::string *wantsToChangeScene;
  std::map<std::string, GameObject *> gameObjects;

protected:
  void changeState(std::string stateName);
  void addGameObject(const std::string &name, GameObject &gameObject);

public:
  explicit Scene(GameState &gameState);
  ~Scene();

  virtual void onStart();
  virtual void onUpdate();
  virtual void onRender();
  virtual void onDestroy();
};
