#include "pch.h"
#include "Collider.h"
#include <iostream>
using namespace std;
Collider::Collider(RectangleShape& body) :
	body(body)
{
}

Collider::~Collider()
{
}
//return types -> 0 - no damage, 1 - damage to player, 2 - damage to enemy
int Collider::CheckColision(Collider other, float push, int option, int type)
{
	Vector2f otherPosition = other.GetPosition();
	Vector2f otherHalfSize = other.GetHalfSize();
	Vector2f thisPosition = GetPosition();
	Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	//Player hitbox
	otherHalfSize.y = otherHalfSize.y * 0.8;

	//extended hitbox is waving sword (more range)
	if (Keyboard::isKeyPressed(Keyboard::Space))
		otherHalfSize.x = otherHalfSize.x * 0.6;
	else
		otherHalfSize.x = otherHalfSize.x * 0.25;

	//selecting colliging type
	//type: 0 - normal, 1 - Skeleton
	if (type == 1)
	{
		thisHalfSize.x = thisHalfSize.x * 0.30;
		thisHalfSize.y = thisHalfSize.y * 0.65;
	}
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		float Width = 900.0;
		float Height = 900.0;
		float movePlayer = otherHalfSize.x * 2.6;
		float moveEnemy = thisHalfSize.x * 0;

		switch (option)
		{
			//Kolizja z przeszkod¹
		case 0:
		case -1:
			push = std::min(std::max(push, 0.0f), 1.0f);

			if (intersectX > intersectY)
			{
				if (deltaX > 0.0f)
				{
					Move(intersectX * (1.0f - push), 0.0f);
					other.Move(-intersectX * push, 0.0f);
				}
				else
				{
					Move(-intersectX * (1.0f - push), 0.0f);
					other.Move(intersectX * push, 0.0f);

				}
			}
			else
			{
				if (deltaY > 0.0f)
				{
					Move(0.0f, intersectY * (1.0f - push));
					other.Move(0.0f, -intersectY * push);
				}
				else
				{
					Move(0.0f, -intersectY * (1.0f - push));
					other.Move(0.0f, intersectY * push);

				}
			}
			return 0;
			//odpychanie gracza
		case 1:
			if (intersectX > intersectY)
			{
				if (deltaX > 0.0f)
				{	//gracz z prawej
					if (otherPosition.x >= Width - movePlayer)
					{
						Move(Width - otherPosition.x - 5, 0.0f);
						other.Move(movePlayer, 0.0f);
					}
					else
					{
						Move(-moveEnemy, 0.0f);
						other.Move(movePlayer, 0.0f);
					}
				}
				else
				{//Z lewej
					if (otherPosition.x <= 0 - 80)
					{
						Move(moveEnemy, 0.0f);
						other.Move(-1 * otherPosition.x, 0.0f);
					}
					else
					{
						Move(moveEnemy, 0.0f);
						other.Move(-movePlayer, 0.0f);
					}

				}
			}
			else
			{
				if (deltaY > 0.0f)
				{
					Move(0.0f, -moveEnemy);
					other.Move(0.0f, movePlayer);
				}
				else
				{
					Move(0.0f, moveEnemy);
					other.Move(0.0f, -movePlayer);

				}
			}
			return 1;


		case 2:
			movePlayer = 20;
			moveEnemy = 40;
			if (intersectX > intersectY)
			{

				if (deltaX > 0.0f)
				{	//gracz z prawej
					if (otherPosition.x >= Width - movePlayer)
					{
						Move(Width - otherPosition.x - 5, 0.0f);
						other.Move(movePlayer, 0.0f);
					}
					else
					{
						Move(-moveEnemy, 0.0f);
						other.Move(movePlayer, 0.0f);
					}
				}
				else
				{//Z lewej
					if (otherPosition.x <= 0 - 80)
					{
						Move(moveEnemy, 0.0f);
						other.Move(-1 * otherPosition.x, 0.0f);
					}
					else
					{
						Move(moveEnemy, 0.0f);
						other.Move(-movePlayer, 0.0f);
					}
				}
				return 2;
			}
			else
			{

				//od gory
				if (deltaY > 0.0f)
				{
					Move(0.0f, -40);
					other.Move(0.0f, movePlayer);
					return 2;
				}
				//OD DOLU
				else
				{
					Move(0.0f, moveEnemy);
					other.Move(0.0f, -movePlayer);
					return 1;
				}
			}

			//tylko prawo, lewo
		case 3:
			movePlayer = 20;
			moveEnemy = 40;
			if (intersectX > intersectY)
			{

				if (deltaX > 0.0f)
				{	//gracz z prawej
					if (otherPosition.x >= Width - movePlayer)
					{
						Move(Width - otherPosition.x - 5, 0.0f);
						other.Move(movePlayer, 0.0f);
					}
					else
					{
						Move(-moveEnemy, 0.0f);
						other.Move(movePlayer, 0.0f);
					}
				}
				else
				{//Z lewej
					if (otherPosition.x <= 0 - 80)
					{
						Move(moveEnemy, 0.0f);
						other.Move(-1 * otherPosition.x, 0.0f);
					}
					else
					{
						Move(moveEnemy, 0.0f);
						other.Move(-movePlayer, 0.0f);
					}
				}
				return 2;
			}
			else
			{
				moveEnemy = 0;
				//od gory
				if (deltaY > 0.0f)
				{
					Move(0.0f, -40);
					other.Move(0.0f, movePlayer);
					return 2;
				}
				//OD DOLU
				else
				{
					Move(0.0f, moveEnemy);
					other.Move(0.0f, -movePlayer);
					return 1;
				}
			}

			//tylko gora, dol
		case 4:
			movePlayer = 20;
			moveEnemy = 40;
			if (intersectX > intersectY)
			{
				moveEnemy = 0;
				if (deltaX > 0.0f)
				{
					//gracz z prawej
					if (otherPosition.x >= Width - movePlayer)
					{
						Move(Width - otherPosition.x - 5, 0.0f);
						other.Move(movePlayer, 0.0f);
					}
					else
					{
						Move(-moveEnemy, 0.0f);
						other.Move(movePlayer, 0.0f);
					}
				}
				else
				{//Z lewej
					if (otherPosition.x <= 0 - 80)
					{
						Move(moveEnemy, 0.0f);
						other.Move(-1 * otherPosition.x, 0.0f);
					}
					else
					{
						Move(moveEnemy, 0.0f);
						other.Move(-movePlayer, 0.0f);
					}
				}
				return 2;
			}
			else
			{

				//od gory
				if (deltaY > 0.0f)
				{
					Move(0.0f, -40);
					other.Move(0.0f, movePlayer);
					return 2;
				}
				//OD DOLU
				else
				{
					Move(0.0f, moveEnemy);
					other.Move(0.0f, -movePlayer);
					return 1;
				}
			}
			//odpychanie gracza daleko niezabezpieczone
			//case 5:
			//if (intersectX > intersectY)
			//{
			//	if (deltaX > 0.0f)
			//	{//z prawej
			//		if (otherPosition.x >= Width - 80)
			//		{
			//			Move(0.0f, 0.0f);
			//			other.Move(Width - otherPosition.x - 33, 0.0f);

			//		}
			//		else if (otherPosition.x == Width - 33)
			//		{

			//			Move(0.0f, 0.0f);
			//			other.Move(00.0f, 0.0f);
			//		}
			//		else
			//		{// z lewej
			//			Move(0.0f, 0.0f);
			//			other.Move(80.0f, 0.0f);
			//		}

			//	}
			//	else
			//	{
			//		Move(0.0f, 0.0f);
			//		other.Move(-80.0f, 0.0f);

			//	}
			//}
			//else
			//{
			//	if (deltaY > 0.0f)
			//	{
			//		Move(0.0f, 0.0f);
			//		other.Move(0.0f, 80.0f);
			//	}
			//	else
			//	{
			//		Move(0.0f, 0.0f);
			//		other.Move(0.0f, -80.0f);

			//	}
			//}
			//return true;
			//odpychanie przeciwnika (przy ataku mieczem)

		}
	}
	return 90;
}
