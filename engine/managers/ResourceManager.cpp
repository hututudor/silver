#include "ResourceManager.h"

std::map<std::string, sf::Texture *> ResourceManager::textures;
std::map<std::string, sf::Font *> ResourceManager::fonts;
std::map<std::string, sf::Music *> ResourceManager::audios;

void ResourceManager::free() {
  freeTextures();
  freeFonts();
  freeAudios();
}

void ResourceManager::loadTexture(const std::string &name, const std::string &fileName, bool smooth) {
  textures[name] = new sf::Texture;

  if (!textures[name]->loadFromFile(fileName)) {
    std::cout << "Error loading texture " << name << " from " << fileName << std::endl;
  }

  textures[name]->setSmooth(smooth);
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

void ResourceManager::loadAudio(const std::string &name, const std::string &fileName) {
  audios[name] = new sf::Music();

  if(!audios[name]->openFromFile(fileName)) {
    std::cout << "Error loading audio " << name << " from " << fileName << std::endl;
  }
}

void ResourceManager::freeAudios() {
  for (auto &it: audios) {
    delete it.second;
  }

}

