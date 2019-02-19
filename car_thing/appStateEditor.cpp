#include "pch.h"
#include "appStateEditor.h"



void appStateEditor::draw(const float dt)
{
	this->application->window.clear(sf::Color::Black);
	this->application->window.draw(this->application->background);

}

void appStateEditor::update(const float dt)
{
}

void appStateEditor::handleInput()
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
			appView.setSize(event.size.width, event.size.height);
			guiView.setSize(event.size.width, event.size.height);

			this->application->background.setPosition(this->application->
				window.mapPixelToCoords(sf::Vector2i(0, 0), this->guiView));
			this->application->background.setScale(
				float(event.size.width) / float(this->application->
					background.getTexture()->getSize().x),
				float(event.size.width) / float(this->application->
					background.getTexture()->getSize().y));
			break;
		}
		default:
			break;
		}
	}
}

appStateEditor::appStateEditor(Application * application)
{
	this->application = application;
	sf::Vector2f pos = sf::Vector2f(this->application->window.getSize());
	this->guiView.setSize(pos);
	this->appView.setSize(pos);
	pos *= 0.5f;
	this->guiView.setCenter(pos);
	this->appView.setCenter(pos);
}

appStateEditor::~appStateEditor()
{
}
