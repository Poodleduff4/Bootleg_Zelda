#pragma once

#include <iostream>
//#include <Windows.h>
#include <SFML/Graphics.hpp>
#include <math.h>


class Cursor
{
public:
	sf::Texture texture;
	sf::Sprite sprite;

	Cursor(sf::Texture& t) {
		sprite.setOrigin(25, 25);
		t.setSmooth(true);
		sprite.setTexture(t);
	}
};
