#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

using namespace sf;
class Enemy
{
public:
	//Enemy(float x_in, float y_in, float speed);
	Enemy(Texture* texture, Vector2u imageCount, float switchTime, float x_in, float y_in, float speed);
	~Enemy();

	void HpLoss(int damage);
	void Movement(int option, float start, float end, float deltaTime);
	void Draw(RenderWindow& window);
	int ReadHp();

	// Do kolizji
	Vector2f GetPosition()
	{
		return body.getPosition();
	}

	Collider GetCollider()
	{
		return Collider(body);
	}

public:
	Vector2f position;
	Vector2f movement;
	float speed;
	float speedMulti = 1.0;
	int directionX = 1;
	int directionY = 1;
	void Animate( float deltaTime);


private:
	int HP = 50;
	RectangleShape body;
	Animation animation;
	unsigned int row;
	bool faceRight;
};

