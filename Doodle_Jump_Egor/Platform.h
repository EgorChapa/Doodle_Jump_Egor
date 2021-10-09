#pragma once
#include <SFML/Graphics.hpp>
class Platform
{
	int platX = 200, platY = 700;
	sf::Texture platform;
	sf::Sprite sprite2;
public:
	Platform(int x, int y) {
		this->platform.loadFromFile("C:\\Users\\Erop\\source\\repos\\Doodle_Jump_Egor\\Doodle_Jump_Egor\\platform.png");
		this->sprite2.setTexture(this->platform);
		this->sprite2.setPosition(platX, platY);
	}
	int point() {
		return platY;
	}
	sf::Sprite getSprite2() {
		return this->sprite2;
	}
};

