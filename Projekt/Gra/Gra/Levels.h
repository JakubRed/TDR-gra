#pragma once
#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h> //for sleep(1000)
#include "Player.h"
#include "Platform.h"
#include "Enemy.h"
#include <time.h>
#include "Menu.h"
#include "Border.h"
#include "LevelUp.h"
#include "SureMenu.h"
#include "Heart.h"

using namespace sf;
using namespace std;

class Levels
{
public:
	int Level1();
	int Level2();
	int Level3();
	Levels(int difficulty, int option);
	~Levels();
private:
	bool keyVisible = true;
	bool alive = true;
	//0 - Easy, 1 - Normal, 2 - Hard, 3 - Insane
	float scoreMultiplier;
	float score;
	int time;
	bool inseane = false;
	bool easy = false;
	bool QuestionPause = false;
	bool EscapeQuestion = false;
	int framerate = 60;


	struct Properties
	{
		int HP;
		int playerDamage = 10;
		//czy przeciwnik istnieje
		bool enemy1 = true, 
			 enemy2 = true, 
			 enemy3 = true,
			 enemy4 = true, 
			 enemy5 = true;
		//czy drzwi otwate
		bool open = false;
	};
	Properties Level[3];
};