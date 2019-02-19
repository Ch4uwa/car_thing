#include "pch.h"
#include "resourceManager.h"


void resourceManager::loadTexture(const std::string & name, const std::string & filename)
{
	sf::Texture tex;
	tex.loadFromFile(filename);

	this->textures[name] = tex;

}

void resourceManager::loadFont(const std::string & name, const std::string & filename)
{
	sf::Font fon;
	fon.loadFromFile(filename);

	this->fonts[name] = fon;

}

sf::Texture & resourceManager::getTextureRef(const std::string & texture)
{
	return this->textures.at(texture);
}

sf::Font & resourceManager::getFontRef(const std::string & font)
{
	return this->fonts.at(font);
}

resourceManager::resourceManager()
{
}


resourceManager::~resourceManager()
{
}
