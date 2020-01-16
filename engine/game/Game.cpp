#include <iostream>
#include "Game.h"

Game::Game(Vector2i size, const int antialiasingLevel, const int &windowStyle) {
  sf::ContextSettings settings;
  settings.antialiasingLevel = antialiasingLevel;

  window = new sf::RenderWindow(sf::VideoMode(size.x, size.y), "Silver window", windowStyle, settings);
  window->setKeyRepeatEnabled(false);

  initMouse();
}

void Game::initMouse() {
  Mouse::releaseButton("right");
  Mouse::releaseButton("left");
  Mouse::releaseButton("middle");
  Mouse::releaseButton("extra1");
  Mouse::releaseButton("extra2");
}

Game::~Game() {
  delete window;
}

void Game::handleEvents(sf::Event event) {
  if (event.type == sf::Event::Closed) {
    window->close();
  } else if (event.type == sf::Event::Resized) {
    window->setSize(Vector2u(event.size.width, event.size.height).toSfVector());
  } else if (event.type == sf::Event::TextEntered) {
    // Todo: Handle text entered event
  } else if (event.type == sf::Event::MouseButtonPressed) {
    handleMousePressedEvent(event.mouseButton.button);
  } else if (event.type == sf::Event::MouseButtonReleased) {
    handleMouseReleaseEvent(event.mouseButton.button);
  } else if (event.type == sf::Event::MouseMoved) {
    Mouse::setPosition(Vector2f(event.mouseMove.x, event.mouseMove.y));
  } else if(event.type == sf::Event::KeyPressed) {
    handleKeyboardPressedEvent(event.key.code);
  } else if(event.type == sf::Event::KeyReleased) {
    handleKeyboardReleasedEvent(event.key.code);
  }
}

void Game::handleMousePressedEvent(sf::Mouse::Button button) {
  if (button == sf::Mouse::Right) {
    Mouse::pressButton("right");
  } else if (button == sf::Mouse::Left) {
    Mouse::pressButton("left");
  } else if (button == sf::Mouse::Middle) {
    Mouse::pressButton("middle");
  } else if (button == sf::Mouse::XButton1) {
    Mouse::pressButton("extra1");
  } else if (button == sf::Mouse::XButton2) {
    Mouse::pressButton("extra2");
  }
}

void Game::handleMouseReleaseEvent(sf::Mouse::Button button) {
  if (button == sf::Mouse::Right) {
    Mouse::releaseButton("right");
  } else if (button == sf::Mouse::Left) {
    Mouse::releaseButton("left");
  } else if (button == sf::Mouse::Middle) {
    Mouse::releaseButton("middle");
  } else if (button == sf::Mouse::XButton1) {
    Mouse::releaseButton("extra1");
  } else if (button == sf::Mouse::XButton2) {
    Mouse::releaseButton("extra2");
  }
}

void Game::handleKeyboardPressedEvent(sf::Keyboard::Key key) {
  Keyboard::pressKey(key);
}

void Game::handleKeyboardReleasedEvent(sf::Keyboard::Key key) {
  Keyboard::releaseKey(key);
}

void Game::start(const std::string &sceneName) {
  currentScene = scenes[sceneName];
  *wantsToChangeScene = std::string();

  currentScene->onStart();

  sf::Clock clock;
  sf::Time dt;

  while (window->isOpen()) {
    dt = clock.restart();

    sf::Event event;
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

    window->clear(Color(0, 0, 0, 255).toSfColor());
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
