#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

class ResourceManager {
public:
  static std::map<std::string, sf::Texture *> textures;
  static std::map<std::string, sf::Font *> fonts;

  static void loadTexture(const std::string &name, const std::string &fileName);
  static void freeTextures();

  static void loadFont(const std::string &name, const std::string &fileName);
  static void freeFonts();

  static void free();
};
