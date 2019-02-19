#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class resourceManager
{
private:

	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;

public:

	void loadTexture(const std::string& name, const std::string& filename);
	void loadFont(const std::string& name, const std::string& filename);

	sf::Texture& getTextureRef(const std::string& texture);
	sf::Font& getFontRef(const std::string& font);

	resourceManager();
	~resourceManager();
};

#endif // !RESOURCEMANAGER_H
