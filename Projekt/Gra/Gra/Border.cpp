#include "pch.h"
#include "Border.h"


Border::Border(Vector2f size, Vector2f position)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setPosition(position);
	body.setFillColor(Color(150, 150, 170));
}


Border::~Border()
{
}

void Border::Draw(RenderWindow& window)
{
	window.draw(body);
}
