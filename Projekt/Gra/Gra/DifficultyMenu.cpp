#include "pch.h"
#include "DifficultyMenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

DifficultyMenu::DifficultyMenu(float width, float height)
{
	if (!DifMenuFont.loadFromFile("../../Fonts/GrandHotel-Regular.otf"))
	{
		cout << "Brak czcionki!";
		return;
	}

	Question.setCharacterSize(84);
	Question.setFont(DifMenuFont);
	Question.setString("Difficulty");
	Question.setFillColor(Color::Red);
	Question.setPosition(Vector2f(width / 3, height / 9));

	menu[0].setFont(DifMenuFont);
	menu[0].setCharacterSize(64);
	menu[0].setFillColor(Color::White);
	menu[0].setString("Easy");
	menu[0].setPosition(Vector2f(width / 2.6, height / (Options + 4) * 3));

	menu[1].setFont(DifMenuFont);
	menu[1].setCharacterSize(64);
	menu[1].setFillColor(Color::Red);
	menu[1].setString("Normal");
	menu[1].setPosition(Vector2f(width / 2.6, height / (Options + 4) * 4));

	menu[2].setFont(DifMenuFont);
	menu[2].setCharacterSize(64);
	menu[2].setFillColor(Color::White);
	menu[2].setString("Hard");
	menu[2].setPosition(Vector2f(width / 2.6, height / (Options + 4) * 5));

	menu[3].setFont(DifMenuFont);
	menu[3].setCharacterSize(64);
	menu[3].setFillColor(Color::White);
	menu[3].setString("Inseane");
	menu[3].setPosition(Vector2f(width / 2.6, height / (Options + 4) * 6));

}


void DifficultyMenu::draw(RenderWindow &window)
{
	for (int i = 0; i < Options; i++)
	{
		window.draw(menu[i]);
	}
	window.draw(Question);
}




void DifficultyMenu::moveUp()
{
	if (selectedItem >= 0 && selectedItem < Options)
	{
		menu[selectedItem].setFillColor(Color::White);
		menu[selectedItem].setStyle(Text::Regular);
		selectedItem--;
		if (selectedItem < 0)
			selectedItem = Options - 1;
		menu[selectedItem].setFillColor(Color::Red);
		menu[selectedItem].setStyle(Text::Bold);
	}
}

void DifficultyMenu::moveDown()
{
	if (selectedItem >= 0 && selectedItem < Options)
	{
		menu[selectedItem].setFillColor(Color::White);
		menu[selectedItem].setStyle(Text::Regular);
		selectedItem++;
		if (selectedItem >= Options)
			selectedItem = 0;
		menu[selectedItem].setFillColor(Color::Red);
		menu[selectedItem].setStyle(Text::Bold);
	}

}
