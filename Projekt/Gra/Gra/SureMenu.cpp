#include "pch.h"
#include "SureMenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>


SureMenu::SureMenu(float width, float height)
{
	if (!SureMenuFont.loadFromFile("../../Fonts/GrandHotel-Regular.otf"))
	{
		cout << "Brak czcionki!";
		return;
	}

	hpSign.setStyle(Text::Bold);
	hpSign.setCharacterSize(35);
	hpSign.setPosition({ 450, 20 });
	hpSign.setFont(SureMenuFont);
	hpSign.setString(convert.str());
	hpSign.setFillColor(Color::Red);

	Question.setCharacterSize(40);
	Question.setFont(SureMenuFont);
	Question.setString("Are you sure?");
	Question.setFillColor(Color(237, 170, 14));
	Question.setPosition(Vector2f(width / 2.3, height / 2.6));

	Dead.setCharacterSize(140);
	Dead.setFont(SureMenuFont);
	Dead.setString("YOU DIED");
	Dead.setFillColor(Color::Red);
	Dead.setPosition(Vector2f(width / 4.3, height / 2.4));

	truth.setCharacterSize(80);
	truth.setFont(SureMenuFont);
	truth.setString("THE FIGHT NEVER ENDS:(\n YOU MUST GO ON \n UNTIL YOU BREAK");
	//truth.setFillColor(Color::Red);
	truth.setPosition(Vector2f(width / 8, height / 2.4));

	SureMenuOption[0].setFont(SureMenuFont);
	SureMenuOption[0].setCharacterSize(50);
	SureMenuOption[0].setFillColor(Color::White);
	SureMenuOption[0].setString("Yes");
	SureMenuOption[0].setPosition(Vector2f(width / (Options + 1) * 1, height / 2));

	SureMenuOption[1].setFont(SureMenuFont);
	SureMenuOption[1].setCharacterSize(40);
	SureMenuOption[1].setFillColor(Color(237, 170, 14));
	SureMenuOption[1].setString("No");
	SureMenuOption[1].setPosition(Vector2f(width / (Options + 1) * 2, height / 2));
}

void SureMenu::draw(RenderWindow &window)
{
	for (int i = 0; i < Options; i++)
	{
		window.draw(SureMenuOption[i]);
	}
	window.draw(Question);
}

void SureMenu::drawDead(RenderWindow & window)
{
	window.draw(Dead);
}

void SureMenu::Truth(RenderWindow & window)
{
	window.draw(truth);
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
		SureMenuOption[selectedItem].setFillColor(Color(237, 170, 14));
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
		SureMenuOption[selectedItem].setFillColor(Color(237, 170, 14));
		SureMenuOption[selectedItem].setStyle(Text::Bold);
	}

}

void SureMenu::showHp(int hp)
{
	convert.str("");
	convert << hp;
	hpSign.setString(convert.str());
}