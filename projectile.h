#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
//#include <Windows.h>
#include "Enemy.h"
#include "boss.h"
#include "Animation.h"
#include "Textures.h"


#include <vector>
extern sf::Vector2f getVectorPath(sf::Vector2f, sf::Vector2f);
extern std::vector<Enemy> enemies;

int getQuadrant90(sf::Vector2f angle) {
	if (angle.x < 0)
	{
		return 1;
	}
	return 0;
}



class Projectile
{
public:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f velocity;
	float maxSpeed = 20;
	int damage;
	Animation anim;
	float projectile_rotation;
	


	Projectile() {}

	Projectile(sf::Texture& t, sf::Vector2f pos, int speed, Animation a, float scale = 1, float proj_rotation) {
		sprite.setPosition(pos);
		sprite.setTexture(t);
		sprite.setOrigin(t.getSize().x / 2, t.getSize().y / 2);
		sprite.setScale(sf::Vector2f(scale, scale));
		anim = a;
		maxSpeed = speed;
		projectile_rotation = proj_rotation;
	}

	Projectile(sf::Texture* t, sf::Vector2f pos, int speed, Animation a, float scale = 1, float proj_rotation) {
		sprite.setPosition(pos);
		sprite.setTexture(*t);
		sprite.setOrigin(t->getSize().x / 2, t->getSize().y / 2);
		sprite.setScale(sf::Vector2f(scale, scale));
		anim = a;
		maxSpeed = speed;
		projectile_rotation = proj_rotation;
	}

	Projectile(sf::IntRect& rect, sf::Vector2f pos, sf::Texture& t, int speed, float proj_rotation) {
		sprite.setTexture(t);
		sprite.setTextureRect(rect);
		sprite.setOrigin(sprite.getTextureRect().width / 2, sprite.getTextureRect().height / 2);
		sprite.setPosition(pos);
		projectile_rotation = proj_rotation;
		//maxSpeed = -maxSpeed;
	}

	void update() {
		sprite.move(velocity * maxSpeed);
		sprite.rotate(projectile_rotation);
	}
};


