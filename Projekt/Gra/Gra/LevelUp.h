#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"
#include "Animation.h"
using namespace sf;

class LevelUp
{
public:
	LevelUp(Texture* texture, Vector2u imageCount, float switchTime, float x_in, float y_in);

	void Draw(RenderWindow& window);

	Collider GetCollider()
	{
		return Collider(body);
	}
	Vector2f position;
	void doorAnimation(bool open, float deltaTime);
private:
	RectangleShape body;
	Animation animation;
	int empty = 1;
};

