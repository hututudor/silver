#include <iostream>
#include "Game.h"

Game::Game(Vector2i size, const int &windowStyle) {
  window = new sf::RenderWindow(sf::VideoMode(size.x, size.y), "Silver window", windowStyle);
}

Game::~Game() {
  delete window;
}

void Game::handleEvents(sf::Event event) {
  if (event.type == sf::Event::Closed)
    window->close();
}

void Game::start(const std::string &sceneName) {
  currentScene = scenes[sceneName];
  *wantsToChangeScene = std::string();

  currentScene->onStart();

  sf::Clock clock;
  sf::Time dt;

  while (window->isOpen()) {
    dt = clock.restart();

    sf::Event event{};
    while (window->pollEvent(event)) {
      handleEvents(event);
    }

    if (!wantsToChangeScene->empty()) {
      std::cout << "Changing state: " << *wantsToChangeScene << std::endl;
      currentScene->onDestroy();
      currentScene = scenes[*wantsToChangeScene];
      currentScene->onStart();
      *wantsToChangeScene = std::string();
    }

    currentScene->onUpdate(dt.asSeconds());

    window->clear(sf::Color::Black);
    currentScene->onRender(window);
    window->display();
  }
}

void Game::stop() {
  window->close();
}

void Game::changeScene(std::string *sceneName) {
  wantsToChangeScene = sceneName;
}

void Game::setWindowTitle(const std::string &title) {
  window->setTitle(title);
}

void Game::setWindowSize(const Vector2u &size) {
  window->setSize(size.toSfVector());
}

void Game::setWindowPosition(const Vector2i &position) {
  window->setPosition(position.toSfVector());
}

void Game::setVSync(const bool &enabled) {
  window->setVerticalSyncEnabled(enabled);
}

void Game::setFramerate(const int &framerate) {
  window->setFramerateLimit(framerate);
}

Vector2u Game::getWindowSize() {
  return Vector2u::fromSfVector(window->getSize());
}

Vector2i Game::getWindowPosition() {
  return Vector2i::fromSfVector(window->getPosition());
}

void Game::addScene(const std::string &name, Scene *scene) {
  scenes[name] = scene;
}

void Game::addScenes(const std::map<std::string, Scene *> scenes) {
  for (auto &it : scenes) {
    addScene(it.first, it.second);
  }
}

GameState Game::getState() {
  GameState gs{};
  gs.wantsToChangeScene = wantsToChangeScene;
  return gs;
}
