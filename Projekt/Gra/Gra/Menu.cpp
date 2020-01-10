#include "pch.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;
Menu::Menu(float width, float height)
{
	if (!MainMenuFont.loadFromFile("../../Fonts/GreatVibes-Regular.otf"))
	{
		cout << "Brak czcionki!";
		return;
	}

	menu[0].setFont(MainMenuFont);
	menu[0].setCharacterSize(64);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("New game");
	menu[0].setPosition(Vector2f(width / 2.6, height / (Options + 2) * 1));

	menu[1].setFont(MainMenuFont);
	menu[1].setCharacterSize(64);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Leaderbord");
	menu[1].setPosition(Vector2f(width / 2.6, height / (Options + 2) * 2));

	menu[2].setFont(MainMenuFont);
	menu[2].setCharacterSize(64);
	menu[2].setFillColor(Color::White);
	menu[2].setString("Options");
	menu[2].setPosition(Vector2f(width / 2.6, height / (Options + 2) * 3));

	menu[3].setFont(MainMenuFont);
	menu[3].setCharacterSize(64);
	menu[3].setFillColor(Color::White);
	menu[3].setString("Credits");
	menu[3].setPosition(Vector2f(width / 2.6, height / (Options + 2) * 4));

	menu[4].setFont(MainMenuFont);
	menu[4].setCharacterSize(64);
	menu[4].setFillColor(Color::White);
	menu[4].setString("Exit");
	menu[4].setPosition(Vector2f(width / 2.6, height / (Options + 2) * 5));
}

void Menu::draw(RenderWindow &window)
{
	for (int i = 0; i < Options; i++)
	{
		window.draw(menu[i]);
	}
}


void Menu::moveUp()
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

void Menu::moveDown()
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
