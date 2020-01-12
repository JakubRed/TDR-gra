#include "pch.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;	
Menu::Menu(float width, float height)
{
	if (!MenuFont.loadFromFile("../../Fonts/GrandHotel-Regular.otf"))
	{
		cout << "Brak czcionki!";
		return;
	}

	Sign.setCharacterSize(104);
	Sign.setFont(MenuFont);
	Sign.setString("THE DUNGEON REDMER");
	Sign.setFillColor(Color::Red);
	Sign.setPosition(Vector2f(width / 8, height / 9.5));

	menu[0].setFont(MenuFont);
	menu[0].setCharacterSize(64);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("New game");
	menu[0].setPosition(Vector2f(width / 2.6, height / (Options + 3) * 2.2));

	menu[1].setFont(MenuFont);
	menu[1].setCharacterSize(64);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Continue");
	menu[1].setPosition(Vector2f(width / 2.6, height / (Options + 3) * 3.2));

	menu[2].setFont(MenuFont);
	menu[2].setCharacterSize(64);
	menu[2].setFillColor(Color::White);
	menu[2].setString("Options");
	menu[2].setPosition(Vector2f(width / 2.6, height / (Options + 3) * 4.2));

	menu[3].setFont(MenuFont);
	menu[3].setCharacterSize(64);
	menu[3].setFillColor(Color::White);
	menu[3].setString("Credits");
	menu[3].setPosition(Vector2f(width / 2.6, height / (Options + 3) * 5.2));

	menu[4].setFont(MenuFont);
	menu[4].setCharacterSize(64);
	menu[4].setFillColor(Color::White);
	menu[4].setString("Exit");
	menu[4].setPosition(Vector2f(width / 2.6, height / (Options + 3) * 6.2));

	{//fraw credits
		credits.setCharacterSize(80);
		credits.setFont(MenuFont);
		credits.setString("This Video Game Brought to You By:\n\n\t\t\tJakub Redmerski\n\n\t\t\t with the help of\n\t\t\tStanislaw Pomykacz");
		credits.setFillColor(Color::Red);
		credits.setPosition(Vector2f(width / 8.2,  height/ 8.2));
	}
}

void Menu::draw(RenderWindow &window)
{
	for (int i = 0; i < Options; i++)
	{
		window.draw(menu[i]);
	}
	window.draw(Sign);
}



void Menu::drawCredits(RenderWindow & window)
{
	window.draw(credits);
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
