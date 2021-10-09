#pragma once
#include <SFML/Graphics.hpp>
#include "Platform.h"
#include <chrono>
#include <thread>

class Doodle
{
	int x = 0, y = 0, u = 0, playerX = 200, playerY = 0, playerYmain = 700;
	sf::Texture doodle;
	sf::Sprite sprite;
	Platform* platform;
public:

	Doodle(int x, int y) {
		this->doodle.loadFromFile("C:\\Users\\Erop\\source\\repos\\Doodle_Jump_Egor\\Doodle_Jump_Egor\\doodle.png");
		this->sprite.setTexture(this->doodle);
	}

	void jump() {
			if (y <= 100) {
				playerY = playerYmain - y;
				y++;
				sprite.setPosition(playerX, playerY);
				std::this_thread::sleep_for(std::chrono::milliseconds(2));
			}
			else{
				playerY = playerY + u;
				u++;
				sprite.setPosition(playerX, playerY);
				std::this_thread::sleep_for(std::chrono::milliseconds(4));
			}
	}
	void plat() {
	}

	sf::Sprite getSprite()
	{
		return this->sprite;
	}

};

