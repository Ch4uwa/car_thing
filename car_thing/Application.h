#ifndef APPLICATION_H
#define APPLICATION_H

#include <stack>
#include <SFML/Graphics.hpp>

class stateManager;

class Application
{
public:
	std::stack<stateManager*> states;

	sf::RenderWindow window;

	void pushState(stateManager* state);
	void popState();
	void changeState(stateManager* state);
	stateManager* peekState();

	void appLoop();

	Application();
	~Application();
};

#endif // !APPLICATION_H
