#pragma once

#include <SFML/Graphics.hpp>
#include <cstring>
#include <map>

#include "../math/Vector2.h"
#include "Scene.h"

enum WindowStyle {
  None = sf::Style::None,
  Titlebar = sf::Style::Titlebar,
  Resize = sf::Style::Resize,
  Close = sf::Style::Close,
  Fullscreen = sf::Style::Fullscreen,
  Default = sf::Style::Default,
};

class Game {
private:
  sf::RenderWindow *window;
  std::map<std::string, Scene *> scenes;
  Scene *currentScene;
  std::string *wantsToChangeScene;

  void handleEvents(sf::Event event);

public:
  explicit Game(Vector2i size = Vector2i(800, 600), const int &windowStyle = WindowStyle::Default);
  ~Game();

  void start(const std::string &sceneName);
  void stop();
  void changeScene(std::string *sceneName);
  GameState getState();

  void setWindowTitle(const std::string &title);
  void setWindowSize(const Vector2u &size);
  void setWindowPosition(const Vector2i &position);
  void setVSync(const bool &enabled);
  void setFramerate(const int &framerate);

  Vector2u getWindowSize();
  Vector2i getWindowPosition();

  void addScene(const std::string &name, Scene *scene);
  void addScenes(std::map<std::string, Scene *> scenes);
};
