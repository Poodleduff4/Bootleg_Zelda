#pragma once
#include "SFML/Graphics.hpp"
#include "Enemy.h"
#include "boss.h"
//#include "projectile.h"
#include <vector>

extern bool boss_alive;
extern std::vector<HomingTarget> homingTargets;
extern std::vector<Homing> homingProjectiles;

class HomingTarget
{
public:
	sf::Sprite sprite;
	Enemy* target = nullptr;
	Boss* bTarget = nullptr;
	int numUpdates = 0;
	int id;

	HomingTarget() {}

	HomingTarget(sf::Texture &t, Enemy* tar) {
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
