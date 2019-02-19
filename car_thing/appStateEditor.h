#ifndef APPSTATEEDITOR_H
#define APPSTATEEDITOR_H

#include <SFML/Graphics.hpp>
#include "stateManager.h"


class appStateEditor :
	public stateManager
{
private:
	sf::View appView;
	sf::View guiView;

public:

	void draw(const float dt)override;
	void update(const float dt)override;
	void handleInput();

	appStateEditor(Application* application);
	virtual ~appStateEditor();
};

#endif // !APPSTATEEDITOR_H
