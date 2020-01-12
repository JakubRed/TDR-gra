#include "pch.h"
#include "Enemy.h"
#include "Levels.h"

using namespace sf;
using namespace std;

Enemy::Enemy(Texture* texture, Vector2u imageCount, float switchTime, float x_in, float y_in, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	position.x = x_in;
	position.y = y_in;
	faceRight = true;

	//render enemy according to speed 
	float scale = 1.0;

	if (speed == 0)
		scale = 0.4;
	if (speed > 0 && speed <= 70)
		scale = 1.5;
	if (speed >= 71 && speed <= 130)
		scale = 1;
	if (speed >= 131 && speed <= 170)
		scale = 0.75;
	if (speed >= 171)
		scale = 0.5;

	body.setSize(Vector2f(scale*128.0f, scale*128.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);
}
Enemy::~Enemy()
{
}
//poruszanie

void Enemy::HpLoss(int damage)
{
	HP -= damage;
}

void Enemy::Movement(int option, float start, float end, float deltaTime)
{
	position = body.getPosition();
	movement.x = 0;
	movement.y = 0;

	switch (option)
	{
	case 1:
		//na osi X
		directionY = 0;
		if (position.x <= start)
			directionX = 1;
		if (position.x >= end)
			directionX = -1;
		break;
	case 2:
		//na osi Y
		directionX = 0;
		if (position.y <= start)
			directionY = 1;
		if (position.y >= end)
			directionY = -1;
		break;
	case 3:
		// na obu osiach X i Y
		if (position.x <= start)
			directionX = 1;
		if (position.x >= end)
			directionX = -1;

		if (position.y <= start)
			directionY = 1;
		if (position.y >= end)
			directionY = -1;
		break;
	}

	movement.x += directionX * deltaTime * speed * speedMulti;
	movement.y += directionY * deltaTime * speed * speedMulti;
	
	if (movement.x != 0 || movement.y != 0)
	{ 
		if (movement.x > 0)
		{
			row = 3;
		}
		else if (movement.x < 0)
		{
			row = 1;
		}
		else if (movement.y > 0)
		{
			row = 2;
		}
		else if (movement.y < 0)
		{
			row = 0;
		}
	}
	
	animation.Update(row, deltaTime, 1);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void Enemy::Draw(RenderWindow& window)
{
	window.draw(body);
}

int Enemy::ReadHp()
{
	return HP;
}

void Enemy::Animate(float deltaTime)
{
	animation.Update(row, deltaTime, 1);
	body.setTextureRect(animation.uvRect);
}

