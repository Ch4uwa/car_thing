#ifndef APPLICATION_H
#define APPLICATION_H

#include <stack>
#include <SFML/Graphics.hpp>
#include "resourceManager.h"

class stateManager;

class Application
{
private:
	void loadTextures();
	void loadFonts();
public:
	std::stack<stateManager*> states;

	sf::RenderWindow window;
	resourceManager resmgr;
	sf::Sprite background;
	sf::Font font;

	void pushState(stateManager* state);
	void popState();
	void changeState(stateManager* state);
	stateManager* peekState();

	void appLoop();

	Application();
	~Application();
};

#endif // !APPLICATION_H
