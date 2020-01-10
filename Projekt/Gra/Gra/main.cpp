#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h> //for sleep(1000)
#include <time.h>
#include "Levels.h"
#include "Menu.h"
#include "DifficultyMenu.h"
#include "SureMenu.h"

using namespace sf;
using namespace std;

int main()
{
HOME:
	//<Menu
	int SureMenuOption = 0;
	int menu_selected_flag = 0;
	bool DifficultyMenuActive = false;
	RenderWindow window(VideoMode(1200, 800), "The Dungeon Redmer");

	Menu mainMenu(window.getSize().x, window.getSize().y);
	DifficultyMenu DifMenu(window.getSize().x, window.getSize().y);
	SureMenu sureMenu(window.getSize().x, window.getSize().y);
	int difficulty = 1;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
			{


				if (menu_selected_flag == 0)
				{
					if (event.key.code == Keyboard::Up || event.key.code == Keyboard::W)
					{
						mainMenu.moveUp();
					}

					if (event.key.code == Keyboard::Down || event.key.code == Keyboard::S)
					{
						mainMenu.moveDown();
					}
					if (Keyboard::isKeyPressed(Keyboard::Enter) && mainMenu.getSelectedItem() == 0 || event.key.code == Keyboard::Space && mainMenu.getSelectedItem() == 0)
					{
						Sleep(250);
						cout << "Poziom 1" << endl;
						DifficultyMenuActive = true;
						menu_selected_flag = 1;

						//Levels LVL1(difficulty);
						//LVL1.Level1();
					}
					//Top score
					if (event.key.code == Keyboard::Enter && mainMenu.getSelectedItem() == 1 || event.key.code == Keyboard::Space && mainMenu.getSelectedItem() == 1)
					{
						system("cls");
						cout << "Top Score:" << endl;
						cout << "1. Wikusia";
						menu_selected_flag = 1;
					}

					if (event.key.code == Keyboard::Enter && mainMenu.getSelectedItem() == 2 || event.key.code == Keyboard::Space && mainMenu.getSelectedItem() == 2)
					{
						cout << "options" << endl;
						menu_selected_flag = 1;
						window.close();
						//return 1;
					}

					if (event.key.code == Keyboard::Enter && mainMenu.getSelectedItem() == 3 || event.key.code == Keyboard::Space && mainMenu.getSelectedItem() == 3)
					{

						cout << "Credits" << endl;
						cout << endl << "Made by Jakub Redmerski";
						cout << endl << "Artistic design Stanislaw Pomykacz";
						menu_selected_flag = 1;
					}

					if (event.key.code == Keyboard::Enter && mainMenu.getSelectedItem() == 4 || event.key.code == Keyboard::Space && mainMenu.getSelectedItem() == 4)
					{
						cout << "EXIT" << endl;
						menu_selected_flag = 1;
						window.close();
						//return 1;
					}

					if (event.key.code == Keyboard::Escape)
					{
						window.close();
						menu_selected_flag = 1;
					}
				}
				if (DifficultyMenuActive == true)
				{
					if (event.key.code == Keyboard::Up || event.key.code == Keyboard::W)
					{
						DifMenu.moveUp();
					}

					if (event.key.code == Keyboard::Down || event.key.code == Keyboard::S)
					{
						DifMenu.moveDown();
					}
					if (Keyboard::isKeyPressed(Keyboard::Enter) && DifMenu.getSelectedItem() == 0 || event.key.code == Keyboard::Space && DifMenu.getSelectedItem() == 0)
					{
						SureMenuOption = 1;

						difficulty = 0;
						//window.close();
						DifficultyMenuActive = false;
						Levels LVL1(difficulty);
						LVL1.Level1();
					}
					if (Keyboard::isKeyPressed(Keyboard::Enter) && DifMenu.getSelectedItem() == 1 || event.key.code == Keyboard::Space && DifMenu.getSelectedItem() == 1)
					{
						difficulty = 1;
						window.close();
						DifficultyMenuActive = false;
						Levels LVL1(difficulty);
						LVL1.Level1();
					}

					if (Keyboard::isKeyPressed(Keyboard::Enter) && DifMenu.getSelectedItem() == 2 || event.key.code == Keyboard::Space && DifMenu.getSelectedItem() == 2)
					{
						difficulty = 2;
						window.close();
						DifficultyMenuActive = false;
						Levels LVL1(difficulty);
						LVL1.Level1();
					}

					if (Keyboard::isKeyPressed(Keyboard::Enter) && DifMenu.getSelectedItem() == 3 || event.key.code == Keyboard::Space && DifMenu.getSelectedItem() == 3)
					{
						difficulty = 3;
						window.close();
						DifficultyMenuActive = false;
						Levels LVL1(difficulty);
						LVL1.Level1();
					}

				}
			}
		}
		window.clear();

		if (menu_selected_flag == 0)
		{
			mainMenu.draw(window);
		}
		if (DifficultyMenuActive == true)
		{
			DifMenu.draw(window);
		}
		//int SureMenu jest w levels.h
		if (SureMenuOption == 1)
			sureMenu.draw(window);

		window.display();
	}
	return 8;
}