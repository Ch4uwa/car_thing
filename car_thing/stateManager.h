#ifndef STATEMANAGER_H
#define STATEMANAGER_H


#include "Application.h"


class stateManager
{
public:
	Application* application;

	virtual void draw(const float dt) = 0;
	virtual void update(const float dt) = 0;
	virtual void handleInput() = 0;

};

#endif // !STATEMANAGER_H
