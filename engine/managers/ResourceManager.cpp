#include "ResourceManager.h"

std::map<std::string, sf::Texture *> ResourceManager::textures;
std::map<std::string, sf::Font *> ResourceManager::fonts;

void ResourceManager::loadTexture(const std::string &name, const std::string &fileName) {
  textures[name] = new sf::Texture;

  if (!textures[name]->loadFromFile(fileName)) {
    std::cout << "Error loading texture " << name << " from " << fileName << std::endl;
  }
}

void ResourceManager::freeTextures() {
  for (auto &it: textures) {
    delete it.second;
  }
}

void ResourceManager::loadFont(const std::string &name, const std::string &fileName) {
  fonts[name] = new sf::Font();

  if (!fonts[name]->loadFromFile(fileName)) {
    std::cout << "Error loading font " << name << " from " << fileName << std::endl;
  }
}

void ResourceManager::freeFonts() {
  for (auto &it: fonts) {
    delete it.second;
  }
}


void ResourceManager::free() {
  freeTextures();
}

