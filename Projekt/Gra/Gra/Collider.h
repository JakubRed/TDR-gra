#pragma once
#include  <SFML/Graphics.hpp>

using namespace sf;

class Collider
{
public:
	Collider(RectangleShape& body);
	~Collider();

	void Move(float dx, float dy)
	{
		body.move(dx, dy);
	}

	int CheckColision(Collider other, float push, int option, int type);

	Vector2f GetPosition()
	{
		return body.getPosition();
	}

	Vector2f GetHalfSize()
	{
		return body.getSize() / 2.0f;
	}

protected:
	bool isPlayerAttacking = 0;
private:
	RectangleShape& body;
};

