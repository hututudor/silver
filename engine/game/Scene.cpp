#include "Scene.h"

Scene::Scene(GameState &gameState) {
  this->wantsToChangeScene = gameState.wantsToChangeScene;
}

Scene::~Scene() {
}

void Scene::onStart() {
  for(auto &it: gameObjects) {
    it.second->onStart();
  }
}

void Scene::onUpdate() {
  for(auto &it: gameObjects) {
    it.second->onUpdate();
  }
}

void Scene::onRender() {
  for(auto &it: gameObjects) {
    it.second->onRender();
  }
}

void Scene::onDestroy() {
  for(auto &it: gameObjects) {
    it.second->onDestroy();
  }
}

void Scene::changeState(std::string stateName) {
  *wantsToChangeScene = stateName;
}

void Scene::addGameObject(const std::string &name, GameObject &gameObject) {
  gameObjects[name] = &gameObject;
}
