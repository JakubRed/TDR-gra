#include "pch.h"
#include "Player.h"
#include <iostream>
#include "Collider.h"

using namespace sf;

Player::Player(Texture* texture, Vector2u imageCount, int hp, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 4 + sType;
	HP = hp;
	body.setSize(Vector2f(110.0f, 100.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(780.0f, 120.0f);
	body.setTexture(texture);
}
Player::~Player()
{
}
//poruszanie

void Player::SwordColorAnimation()
{
	if (Keyboard::isKeyPressed(Keyboard::Num1))
	{
		swordType = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Num2))
	{
		swordType = 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Num3))
	{
		swordType = 2;
	}
}

void Player::Update(float deltaTime) {
	//check what type of sword to shop

	//wektor ruchu
	movement.x = 0.0f;
	movement.y = 0.0f;

	//row decider
	switch (swordType)
	{
	case 0:
		sType = 0;
		break;
	case 1:
		sType = 5;
		break;
	case 2:
		sType = 10;
		break;
	}

	//sterowanie ruchem
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		movement.x -= speed * deltaTime;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		movement.x += speed * deltaTime;
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		movement.y -= speed * deltaTime;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		movement.y += speed * deltaTime;
	}

	////zmiana kierunku (prawo lub lewo)
	if (movement.x > 0.0f)
	{
		faceDirection = 1;
	}
	else if (movement.x < 0.0f)
	{
		faceDirection = 2;
	}

	//animacje poruszania
	//sword attack
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		row = 4 + sType;
		isAttacking = 1;
		FastSwordWaving = 3;
	}
	//idle
	else if (movement.x == 0.0f && movement.y == 0.0f)
	{
		row = 3 + sType;
		isAttacking = 0;
		FastSwordWaving = 1;
	}
	//strolling
	else
	{
		row = 1 + sType;
	}

	animation.Update(row, FastSwordWaving * deltaTime, faceDirection);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}
void Player::HpLoss(int amountLost)
{
	HP -= amountLost;
}

int Player::ReadHp()
{
	return HP;
}

void Player::Draw(RenderWindow& window)
{
	window.draw(body);
}



