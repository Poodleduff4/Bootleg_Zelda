#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
//#include <Windows.h>


class Animation
{
public:
	float frame, speed;
	sf::Sprite sprite;
	std::vector<sf::IntRect> frames;

	Animation() {}

	Animation(sf::Texture& t, int x, int y, int w, int h, int count, float spd) {
		frame = 0;
		speed = spd;

		for (size_t i = 0; i < count; i++)
			frames.push_back(sf::IntRect(x + i * w, y, w, h));

		sprite.setTexture(t);
		sprite.setOrigin(w / 2, h / 2);
		sprite.setTextureRect(frames[0]);
	}

	void update() {
		frame += speed;
		int n = frames.size();
		if (frame > n) frame -= n;
		if (n > 0) sprite.setTextureRect(frames[int(frame)]);
	}

	bool isEnd()
	{
		return frame + speed >= frames.size();
	}
};

class AnimationEvent
{
public:
	float x, y, dx, dy, R, angle;
	bool life;
	Animation anim;

	AnimationEvent(Animation& a, int X, int Y) {
		anim = a;
		x = X;
		y = Y;
	}

	AnimationEvent(Animation* a, int X, int Y) {
		//anim = a;
		x = X;
		y = Y;
	}

	void draw(sf::RenderWindow& window) {
		anim.sprite.setPosition(x, y);
		window.draw(anim.sprite);
	}
};
