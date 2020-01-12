#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

#define Options 2
class SureMenu
{

private:
	Text Dead;
	Text Question;
	Font SureMenuFont;
	Text SureMenuOption[Options];//maksymalna liczba poziomow
	int selectedItem = 1;


public:
	SureMenu(float width, float height);//mainMenu

	~SureMenu() {}
	void GOLEFT();//przesun do gory
	void goRight();//przesun w dol
	int getSelectedItem() { return selectedItem; }//zwroc poziom menu
	void draw(RenderWindow &window);//rysuj menu w oknie
	void drawDead(RenderWindow &window);
};