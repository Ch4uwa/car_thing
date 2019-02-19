#include "pch.h"
#include <SFML/System.hpp>

#include "Application.h"
#include "stateManager.h"



void Application::loadTextures()
{
	resmgr.loadTexture("background", "resources/background.jpg");
}

void Application::loadFonts()
{
	resmgr.loadFont("sansation", "resources/sansation.ttf");
}

void Application::pushState(stateManager * state)
{
	this->states.push(state);

	return;
}

void Application::popState()
{
	delete this->states.top();
	this->states.pop();

	return;
}

void Application::changeState(stateManager * state)
{
	if (!this->states.empty())
	{
		popState();
	}
	pushState(state);

	return;
}

stateManager * Application::peekState()
{
	if (this->states.empty()) return nullptr;
	return this->states.top();
}

void Application::appLoop()
{
	sf::Clock clock;

	while (this->window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		if (peekState() == nullptr) continue;
		peekState()->handleInput();
		peekState()->update(dt);
		this->window.clear(sf::Color::Black);
		peekState()->draw(dt);
		this->window.display();

	}
}

Application::Application()
{
	this->loadTextures();
	this->loadFonts();

	this->window.create(sf::VideoMode(windowWIDTH, windowHEIGHT), "\tWoop Woop");
	this->window.setFramerateLimit(60);

	this->background.setTexture(this->resmgr.getTextureRef("background"));
	
}


Application::~Application()
{
	while (!this->states.empty()) popState();
}
