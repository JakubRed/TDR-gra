#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

using namespace sf;
class Player
{
	friend class Collider;//do zmiany wielkoœci hitboxu rycerza

public:

	Player(Texture* texture, Vector2u imageCount, int hp, float switchTime, float speed, int PosX, int PosY);
	~Player();

	void Update(float deltaTime);
	void Draw(RenderWindow& window);

	void HpLoss(int amountLost);
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
	int swordType = 0; //0 - normal, 1 - blue, 2 - red
	bool isAttacking = 0;
	float positionX = body.getPosition().x;
	float positionY = body.getPosition().y;
	float speed;
	void SwordColorAnimation();
	Vector2f movement;
	int faceDirection = 1;
private:
	int HP;
	int FastSwordWaving = 1;
	int sType = 0;
	RectangleShape body;
	Animation animation;
	unsigned int row;
};

