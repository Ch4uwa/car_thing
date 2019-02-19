#ifndef APPSTART_H
#define APPSTART_H

#include <SFML/Graphics.hpp>
#include "stateManager.h"


class appStateStart :
	public stateManager
{
private:

	sf::View view;

public:
	void draw(const float dt)override;
	void update(const float dt)override;
	void handleInput()override;

	appStateStart(Application* application);
};

#endif // !APPSTART_H
