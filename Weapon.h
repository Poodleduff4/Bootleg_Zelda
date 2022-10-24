#pragma once
#include "SFML/Graphics.hpp"
#include "Textures.h"
#include <iostream>
#include "Animation.h"

class Weapon
{
public:
	sf::Sprite sprite;
	sf::Texture *texture;
	int firerate;
	int damage;
	int speed;
	Animation* animation;
	int type; 
	float projectileRotation;
	//char type[10];
	Weapon() {}
	Weapon(sf::Texture& t, Animation& a, int tp, int fr, int dam, int spd, float proj_rotation) {
		sprite.setTexture(t);
		texture = &t;
		firerate = fr;
		animation = &a;
		damage = dam;
		speed = spd;
		type = tp;
		projectileRotation = proj_rotation;
		/*if (&t == &homingBullet_texture)
		{
			strcpy(type, "homing");
			std::cout << type << '\n';
		}*/
	}
};

namespace Weapons {
	Weapon classic(t1, sExplosion_1, 0, 100, 1, 20, 0);
	Weapon electric(energyBall_projectile, sEnergyBall, 1, 500, 2, 15, 5);
	Weapon homingBullet(homingBullet_texture, sExplosion_3, 2, 200, 10, 7, 0);
}

