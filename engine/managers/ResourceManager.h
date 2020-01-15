#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <iostream>

class ResourceManager {
public:
  static std::map<std::string, sf::Texture *> textures;
  static std::map<std::string, sf::Font *> fonts;
  static std::map<std::string, sf::Music *> audios;

  static void loadTexture(const std::string &name, const std::string &fileName, bool smooth = false);
  static void freeTextures();

  static void loadFont(const std::string &name, const std::string &fileName);
  static void freeFonts();

  static void loadAudio(const std::string &name, const std::string &fileName);
  static void freeAudios();

  static void free();
};
