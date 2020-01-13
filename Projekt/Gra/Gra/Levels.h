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
#include <fstream>

using namespace sf;
using namespace std;

class Levels
{
public:
	int *w = &currentLevel;
	int Level1();
	int Level2();
	int Level3();
	Levels(int difficulty, int option);
	~Levels();
	void saveGame(bool enemy1, bool enemy2, bool enemy3, bool enemy4, bool enemy5, int hp, bool open, int gameDifficulty, int PosX, int PosY, bool keyVisible, int currentLevel);
	void load();
	int returnLevel();
	fstream Save;
private:
	int PosX = 780;
	int PosY = 200;
	int currentLevel = 1;
	bool keyVisible = true;
	bool alive = true;
	//float scoreMultiplier;
	float score;
	//int time;
	bool inseane = false;
	bool easy = false;
	bool QuestionPause = false;
	bool EscapeQuestion = false;
	int framerate = 60;
	int gameDifficulty = 1;	////0 - Easy, 1 - Normal, 2 - Hard, 3 - Insane
		bool enemy1 = true, 
			 enemy2 = true, 
			 enemy3 = true,
			 enemy4 = true, 
			 enemy5 = true;
		bool open = false;

		int i = 1;

	struct Difficulty
	{
		int HP;
		int playerDamage = 10;
		//czy przeciwnik istnieje
		//czy drzwi otwate
	};
	Difficulty Dif[4] = { {1000, 50}, {500, 10}, {500, 5}, {250, 5}};
};