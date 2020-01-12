#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"

using namespace sf;

class Border
{
public:
	Border(Vector2f size, Vector2f position, int Option);
	~Border();

	void Draw(RenderWindow& window);

	Collider GetCollider()
	{
		return Collider(body);
	}
private:
	sf::RectangleShape body;
};

