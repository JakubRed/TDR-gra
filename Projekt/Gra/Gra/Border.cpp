#include "pch.h"
#include "Border.h"


Border::Border(Vector2f size, Vector2f position, int Option)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setPosition(position);

	if (Option == 0)
		body.setFillColor(Color(150, 150, 170));
	if (Option == 1)
		body.setFillColor(Color(114, 131, 148));
}


Border::~Border()
{
}

void Border::Draw(RenderWindow& window)
{
	window.draw(body);
}
