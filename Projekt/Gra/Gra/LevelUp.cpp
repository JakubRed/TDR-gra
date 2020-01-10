#include "pch.h"
#include "LevelUp.h"

LevelUp::LevelUp(Texture* texture, Vector2u imageCount, float switchTime, float x_in, float y_in) :
	animation(texture, imageCount, switchTime)
{
	position.x = x_in;
	position.y = y_in;

	body.setSize(Vector2f(64.0f, 70.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);
}

void LevelUp::Draw(RenderWindow& window)
{
	window.draw(body);
}

void LevelUp::doorAnimation(bool open, float deltaTime)
{
	if (open == false)
		deltaTime = 0.25f;

	animation.Update(1, deltaTime, 1);
	body.setTextureRect(animation.uvRect);
}
