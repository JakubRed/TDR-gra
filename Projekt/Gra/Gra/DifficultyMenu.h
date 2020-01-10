#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

#define Options 4
class DifficultyMenu
{

private:
	Font DifMenuFont;
	Text menu[Options];//maksymalna liczba poziomow
	int selectedItem = 1;


public:
	DifficultyMenu(float width, float height);//mainMenu

	~DifficultyMenu() {}
	void moveUp();//przesun do gory
	void moveDown();//przesun w dol
	int getSelectedItem() { return selectedItem; }//zwroc poziom menu
	void draw(sf::RenderWindow &window);//rysuj menu w oknie
};

