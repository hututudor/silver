#include "Scene.h"

Scene::Scene(GameState &gameState) {
  this->wantsToChangeScene = gameState.wantsToChangeScene;
}

Scene::~Scene() {
}

void Scene::onStart() {
  for (auto &it: gameObjects) {
    it->onStart();
  }
}

void Scene::onUpdate(const float &dt) {
  for (auto &it: gameObjects) {
    it->onUpdate(dt);
  }
}

void Scene::onRender(sf::RenderWindow *window) {
  for (auto &it: gameObjects) {
    it->onRender(window);
  }
}

void Scene::onDestroy() {
  for (auto &it: gameObjects) {
    it->onDestroy();
  }
}

void Scene::changeState(std::string stateName) {
  *wantsToChangeScene = stateName;
}

void Scene::addGameObject(GameObject *gameObject) {
  gameObjects.push_back(gameObject);
}

void Scene::clearGameObjects() {
  gameObjects.clear();
}


