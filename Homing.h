#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
//#include <Windows.h>
#include "Enemy.h"
#include "boss.h"
#include "Animation.h"
#include <vector>

extern bool boss_alive;
//extern std::vector<Homing> homingProjectiles;
//extern std::vector<HomingTarget> homingTargets;
class HomingTarget
{
public:
	sf::Sprite sprite;
	Enemy* target = nullptr;
	Boss* bTarget = nullptr;
	int numUpdates = 0;
	int id;

	HomingTarget() {}

	HomingTarget(sf::Texture& t, Enemy* tar) {
		target = tar;
		sprite.setTexture(t);
		sprite.setOrigin(t.getSize().x / 2, t.getSize().y / 2);
		sprite.setPosition(target->sprite.getPosition());
		id = rand() % 1000;
	}

	HomingTarget(sf::Texture& t, Boss* tar) {
		bTarget = tar;
		sprite.setTexture(t);
		sprite.setOrigin(t.getSize().x / 2, t.getSize().y / 2);
		sprite.setPosition(bTarget->sprite.getPosition());
		id = rand() % 1000;
	}

	void update() {
		if (target != nullptr)
			sprite.setPosition(target->sprite.getPosition());
		else if (bTarget != nullptr)
			sprite.setPosition(bTarget->sprite.getPosition());
	}

	void erase() {
		/*for (size_t i = 0; i < homingTargets.size(); i++)
		{
			if (id == homingProjectiles[i].marker->id)
			{
				homingProjectiles.erase(homingProjectiles.begin() + i);
			}
		}*/
	}
};

class Homing : public Projectile
{
public:
	Enemy* target = nullptr;
	Boss* bTarget = nullptr;
	char type[10];
	HomingTarget marker;
	int numUpdates = 0;
	bool intro = true;
	int introCount = 1;

	Homing(sf::Texture& t, sf::Vector2f pos, Enemy* tar, int speed, Animation& a) {
		target = tar;
		sprite.setPosition(pos);
		sprite.setTexture(t);
		sprite.setOrigin(t.getSize().x / 2, t.getSize().y / 2);
		maxSpeed = speed;
		anim = a;
	}

	Homing(sf::Texture& t, sf::Vector2f pos, Boss* tar, int speed, Animation& a) {
		bTarget = tar;
		sprite.setPosition(pos);
		sprite.setTexture(t);
		sprite.setOrigin(t.getSize().x / 2, t.getSize().y / 2);
		strcpy(type, "boss");
		maxSpeed = speed;
		anim = a;
	}

	Homing(sf::Texture* t, sf::Vector2f pos) {
		sprite.setPosition(pos);
		sprite.setTexture(*t);
		sprite.setOrigin(t->getSize().x / 2, t->getSize().y / 2);
	}

	void update() {
			sf::Vector2f vecPath;
			//std::cout << target->sprite.getPosition().x << " | " << target->sprite.getPosition().y << '\n';
			if (strcmp(type, "boss") != 0 && target != nullptr)
				vecPath = getVectorPath(sprite.getPosition(), target->sprite.getPosition());
			else if (bTarget != nullptr)
				vecPath = getVectorPath(sprite.getPosition(), bTarget->sprite.getPosition());
			sprite.setRotation((std::atan(vecPath.y / vecPath.x) * (float)(180 / 3.14159)) + 180 * getQuadrant90(vecPath));
			//std::cout << std::atan(vecPath.y / vecPath.x) << '\n';
			sprite.move(vecPath*maxSpeed);
		
	}
};
