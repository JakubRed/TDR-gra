#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

#define Options 5
class Menu
{

private:
	Text credits;
	Text Sign;
	Font MenuFont;
	Text menu[Options];//maksymalna liczba poziomow
	int selectedItem = 0;



public:
	Menu(float width, float height);//mainMenu

	~Menu() {}
	void drawCredits(RenderWindow &window);
	void moveUp();//przesun do gory
	void moveDown();//przesun w dol
	int getSelectedItem() { return selectedItem; }//zwroc poziom menu
	void draw(sf::RenderWindow &window);//rysuj menu w oknie
};

