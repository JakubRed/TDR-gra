#include "pch.h"
#include "SureMenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;
SureMenu::SureMenu(float width, float height)
{
	if (!SureMenuFont.loadFromFile("../../Fonts/GrandHotel-Regular.otf"))
	{
		cout << "Brak czcionki!";
		return;
	}
	Question.setCharacterSize(64);
	Question.setFont(SureMenuFont);
	Question.setString("Are you sure?");
	Question.setFillColor(Color::Red);
	Question.setPosition(Vector2f(width /2.5, height / 5.6));

	SureMenuOption[0].setFont(SureMenuFont);
	SureMenuOption[0].setCharacterSize(64);
	SureMenuOption[0].setFillColor(Color::Red);
	SureMenuOption[0].setString("Yes");
	SureMenuOption[0].setPosition(Vector2f(width / (Options + 1.3) * 1, height / 2.6));

	SureMenuOption[1].setFont(SureMenuFont);
	SureMenuOption[1].setCharacterSize(64);
	SureMenuOption[1].setFillColor(Color::White);
	SureMenuOption[1].setString("No");
	SureMenuOption[1].setPosition(Vector2f(width / (Options + 1.3) * 2, height / 2.6));
}

void SureMenu::draw(RenderWindow &window)
{
	for (int i = 0; i < Options; i++)
	{
		window.draw(SureMenuOption[i]);
	}
	window.draw(Question);
}


void SureMenu::GOLEFT()
{
	if (selectedItem >= 0 && selectedItem < Options)
	{
		SureMenuOption[selectedItem].setFillColor(Color::White);
		SureMenuOption[selectedItem].setStyle(Text::Regular);
		selectedItem--;
		if (selectedItem < 0)
			selectedItem = Options - 1;
		SureMenuOption[selectedItem].setFillColor(Color::Red);
		SureMenuOption[selectedItem].setStyle(Text::Bold);
	}
}

void SureMenu::goRight()
{
	if (selectedItem >= 0 && selectedItem < Options)
	{
		SureMenuOption[selectedItem].setFillColor(Color::White);
		SureMenuOption[selectedItem].setStyle(Text::Regular);
		selectedItem++;
		if (selectedItem >= Options)
			selectedItem = 0;
		SureMenuOption[selectedItem].setFillColor(Color::Red);
		SureMenuOption[selectedItem].setStyle(Text::Bold);
	}

}