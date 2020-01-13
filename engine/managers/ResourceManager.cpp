#include "ResourceManager.h"

std::map<std::string, sf::Texture*> ResourceManager::textures;

void ResourceManager::loadTexture(std::string& name, std::string &fileName) {
  textures[name] = new sf::Texture;

  if(!textures[name]->loadFromFile(fileName)) {
    std::cout << "Error loading texture " << name << " from " << fileName << std::endl;
  }
}

void ResourceManager::freeTextures() {
  for(auto &it: textures) {
    delete it.second;
  }
}

void ResourceManager::free() {
  freeTextures();
}
