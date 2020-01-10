#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

#define Options 2
class SureMenu
{

private:
	Text menu[Options];//maksymalna liczba poziomow
	int selectedItem = 0;


public:
	SureMenu(float width, float height);//mainMenu
	bool Choosing();

	~SureMenu() {}
	void moveUp();//przesun do gory
	void moveDown();//przesun w dol
	int getSelectedItem() { return selectedItem; }//zwroc poziom menu
	void draw(sf::RenderWindow &window);//rysuj menu w oknie
};

