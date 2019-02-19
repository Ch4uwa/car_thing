#include "pch.h"
#include "appStateStart.h"
#include "appStateEditor.h"


void appStateStart::draw(const float dt)
{
	this->application->window.setView(this->view);

	this->application->window.clear(sf::Color::Black);
	this->application->window.draw(this->application->background);
}

void appStateStart::update(const float dt)
{
}

void appStateStart::handleInput()
{
	sf::Event event;

	while (this->application->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			this->application->window.close();
			break;
		}
		/* Resize the window */
		case sf::Event::Resized:
		{
			this->view.setSize(event.size.width, event.size.height);

			this->application->background.setPosition(
				this->application->window.mapPixelToCoords(sf::Vector2i(0, 0)));

			this->application->background.setScale(
				float(event.size.width) /
				float(this->application->background.getTexture()->getSize().x),
				float(event.size.height) /
				float(this->application->background.getTexture()->getSize().y));
			break;
		}
		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				this->application->window.close();
			}
			break;
		}
		default:
			break;
		}
	}
}

appStateStart::appStateStart(Application * application)
{
	this->application = application;
	sf::Vector2f pos = sf::Vector2f(this->application->window.getSize());
	this->view.setSize(pos);
	pos *= 0.5f;
	this->view.setCenter(pos);
}
