#pragma once
#define SFML_NO_DEPRECATED_WARNINGS
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <ctime>
#include "Doodle.h"
#include "Platform.h"
class Window : public sf::RenderWindow
{
	Platform* platform;
	Doodle* player;
	sf::Texture background;
	sf::Color _bgColor;
	sf::Text text;
	sf::Font font;
	std::string a;
	int score = atoi(a.c_str());
public:
	Window(int width, int heigth) : sf::RenderWindow(sf::VideoMode(width, heigth), "Hello sfml!") {
		_bgColor = sf::Color::Black;
		font.loadFromFile("arial.ttf");
		text.setFont(font); // font is a sf::Font

		text.setString(a);

		text.setCharacterSize(30);

		text.setFillColor(sf::Color::Black);

		text.setStyle(sf::Text::Bold);
		this->player = new  Doodle(0, 0);
		this->platform = new Platform(0, 0);
	}
	void show() {

		while (this->isOpen())
		{
			sf::Event event;
			while (this->pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					this->close();
				}
				background.loadFromFile("C:\\Users\\Erop\\source\\repos\\Doodle_Jump_Egor\\Doodle_Jump_Egor\\background.png");

			}

			this->clear(this->_bgColor);
			sf::Sprite sprite(background);
			this->draw(sprite);
			this->draw(text);
			this->draw(this->platform->getSprite2());
			player->jump();
			this->draw(this->player->getSprite());
			this->display();
		}
	}

	void setBgColor(int r, int g, int b) {
		this->_bgColor.r = r;
		this->_bgColor.g = g;
		this->_bgColor.b = b;
	}
	void setBgColor(const sf::Color& _color) {
		this->_bgColor = sf::Color(_color);
	}
	~Window() {}
};

