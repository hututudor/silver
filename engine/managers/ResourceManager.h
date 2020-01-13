#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

class ResourceManager {
public:
  static std::map<std::string, sf::Texture *> textures;

  static void loadTexture(std::string& name, std::string &fileName);
  static void freeTextures();

  static void free();
};
