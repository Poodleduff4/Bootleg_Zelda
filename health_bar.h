#include <SFML/Graphics.hpp>
#include "boss.h"
extern sf::RenderWindow window;

class HealthBar
{
public:
	sf::Texture texture;
	sf::Sprite sprite;
	bool alive = true;

	HealthBar(sf::Texture& t, sf::Vector2f pos) {
		sprite.setTexture(t);
		sprite.setOrigin(0, 0);
		sprite.setPosition(pos.x-t.getSize().x/2, pos.y);
	}
	
	void update(float currentHealth, float maxHealth) {
		sprite.setScale(currentHealth / maxHealth, 1.f);
	}

	void reset(sf::Texture& t) {
		sprite.setTexture(t);
		sprite.setScale(1.f, 1.f);
	}
};
