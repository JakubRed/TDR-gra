#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h> //for Sleep(1000)
#include <time.h>
#include "Levels.h"
#include "Menu.h"
#include "DifficultyMenu.h"
#include "SureMenu.h"
#include "OptionMenu.h"
#include <fstream>

using namespace sf;
using namespace std;
void Kupa()
{

}

int main()
{
HOME:
	//<Menu
	int menu_selected_flag = 0;
	bool DifficultyMenuActive = false;
	RenderWindow window(VideoMode(1200, 1000), "The Dungeon Redmer");

	OptionMenu optionMenu(window.getSize().x, window.getSize().y);	

	//Credits
	Menu mainMenu(window.getSize().x, window.getSize().y);
	DifficultyMenu DifMenu(window.getSize().x, window.getSize().y);

	int level_nr = 1;
	int difficulty = 1;	
	int framerate = 60;

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
						DifficultyMenuActive = true;
						menu_selected_flag = 1;
						Sleep(250);
					}
					//Continue
					if (event.key.code == Keyboard::Enter && mainMenu.getSelectedItem() == 1 || event.key.code == Keyboard::Space && mainMenu.getSelectedItem() == 1)
					{
						Levels contin(1, framerate, true);
						contin.load();
						
							switch (contin.returnLevel())
							{
							case 1:
								contin.Level1();
								break;
							case 2:
								contin.Level2();
								break;
							case 3:
								contin.Level3();
								break;
							}
					}
					//options
					if (event.key.code == Keyboard::Enter && mainMenu.getSelectedItem() == 2 || event.key.code == Keyboard::Space && mainMenu.getSelectedItem() == 2)
					{
						menu_selected_flag = 2;
						Sleep(100);
					}
					//credits
					if (event.key.code == Keyboard::Enter && mainMenu.getSelectedItem() == 3 || event.key.code == Keyboard::Space && mainMenu.getSelectedItem() == 3)
					{
						menu_selected_flag = 3;
						Sleep(100);

					}
					//exit
					if (event.key.code == Keyboard::Enter && mainMenu.getSelectedItem() == 4 || event.key.code == Keyboard::Space && mainMenu.getSelectedItem() == 4)
					{
						window.close();
					}
				}

				//difficullty menu
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
						difficulty = 0;
						DifficultyMenuActive = false;
						window.close();
						Levels LVL1(difficulty, framerate, 0);
						LVL1.Level1();
					}
					if (Keyboard::isKeyPressed(Keyboard::Enter) && DifMenu.getSelectedItem() == 1 || event.key.code == Keyboard::Space && DifMenu.getSelectedItem() == 1)
					{
						difficulty = 1;
						DifficultyMenuActive = false;
						window.close();
						Levels New(difficulty, framerate, 0);
						New.Level1();
					}

					if (Keyboard::isKeyPressed(Keyboard::Enter) && DifMenu.getSelectedItem() == 2 || event.key.code == Keyboard::Space && DifMenu.getSelectedItem() == 2)
					{
						difficulty = 2;
						window.close();
						DifficultyMenuActive = false;
						Levels New(difficulty, framerate, 0);
						New.Level1();
					}

					if (Keyboard::isKeyPressed(Keyboard::Enter) && DifMenu.getSelectedItem() == 3 || event.key.code == Keyboard::Space && DifMenu.getSelectedItem() == 3)
					{
						difficulty = 3;
						window.close();
						DifficultyMenuActive = false;
						Levels New(difficulty, framerate, 0);
						New.Level1();
					}

					if (event.key.code == Keyboard::Backspace || event.key.code == Keyboard::Escape)
					{
						menu_selected_flag = 0;
						DifficultyMenuActive = false;
					}
				}

				//option mennu
				if (menu_selected_flag == 2)
				{
					if (event.key.code == Keyboard::D || event.key.code == Keyboard::Right)
					{
						optionMenu.goRight();
					}
					if (event.key.code == Keyboard::A || event.key.code == Keyboard::Left)
					{
						optionMenu.GOLEFT();
					}
					if (Keyboard::isKeyPressed(Keyboard::Enter) && optionMenu.getSelectedItem() == 0 || event.key.code == Keyboard::Space && optionMenu.getSelectedItem() == 0)
					{
						Sleep(100);
						framerate = 30;
						menu_selected_flag = 0;
						DifficultyMenuActive = false;
					}
					if (Keyboard::isKeyPressed(Keyboard::Enter) && optionMenu.getSelectedItem() == 1 || event.key.code == Keyboard::Space && optionMenu.getSelectedItem() == 1)
					{
						Sleep(100);
						menu_selected_flag = 0;
						DifficultyMenuActive = false;
						
					}
					if (Keyboard::isKeyPressed(Keyboard::Enter) && optionMenu.getSelectedItem() == 2 || event.key.code == Keyboard::Space && optionMenu.getSelectedItem() == 2)
					{
						Sleep(100);
						framerate = 144;
						menu_selected_flag = 0;
						DifficultyMenuActive = false;
					}
				}
				if (event.key.code == Keyboard::Backspace || event.key.code == Keyboard::Escape)
				{
					menu_selected_flag = 0;
					DifficultyMenuActive = false;
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
		if (menu_selected_flag == 3)
			mainMenu.drawCredits(window);

		if (menu_selected_flag == 2)
			optionMenu.draw(window);


		window.display();
	}
	return 8;
}