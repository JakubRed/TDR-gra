#include "pch.h"
#include "SureMenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

SureMenu::SureMenu(float width, float height)
{
	Font SureMenuFont;
	if (!SureMenuFont.loadFromFile("../../Fonts/GreatVibes-Regular.otf"))
	{
		cout << "Brak czcionki!";
		return;
	}

	menu[0].setFont(SureMenuFont);
	menu[0].setCharacterSize(64);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("Yes");
	menu[0].setPosition(Vector2f(width / (2 + 1) * 1, height / 2.6));

	menu[1].setFont(SureMenuFont);
	menu[1].setCharacterSize(64);
	menu[1].setFillColor(Color::White);
	menu[1].setString("No");
	menu[1].setPosition(Vector2f(width / (2 + 1) * 1, height / 2.6));
	//width / 2.6, height / (Options + 1) * 2)
}	//width / (2 + 1) * 1, height / 2.6)

bool SureMenu::Choosing()
{

	if (Keyboard::isKeyPressed(Keyboard::Enter) && getSelectedItem() == 1 || Keyboard::isKeyPressed(Keyboard::Space) && getSelectedItem() == 1)
	{
		return false;
	}
	else
		return true;
}


void SureMenu::draw(RenderWindow &window)
{
	for (int i = 0; i < Options; i++)
	{
		window.draw(menu[i]);
	}
}




void SureMenu::moveUp()
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

void SureMenu::moveDown()
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
