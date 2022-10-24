#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
//#include <Windows.h>
#include "Weapon.h"
#define playerSpeed 5


class Player
{
public:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f velocity;
	float maxSpeed = playerSpeed;
	bool alive = true;
	Weapon *weapon;

	Player(sf::Texture& t, sf::Vector2f pos) {
		sprite.setPosition(pos.x, pos.y);
		sprite.setTexture(t);
	}

	void update() {
		sprite.move(velocity * maxSpeed);
		velocity *= 0.f;
	}
};
