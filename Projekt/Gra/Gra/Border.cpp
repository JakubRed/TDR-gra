#include "pch.h"
#include "Border.h"


Border::Border(Vector2f size, Vector2f position)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setPosition(position);
	body.setFillColor(Color(70, 70, 70));
}


Border::~Border()
{
}

void Border::Draw(RenderWindow& window)
{
	window.draw(body);
}
