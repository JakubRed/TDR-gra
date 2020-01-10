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

using namespace sf;
using namespace std;

class Levels
{
public:
	int Level1();
	int Level2();
	int Level3();
	Levels(int difficulty);
	~Levels();
private:
	//0 - Easy, 1 - Normal, 2 - Hard, 3 - Insane
	float scoreMultiplier;
	float score;
	int time;
	int HP;
	int playerDamage = 10;
	bool inseane = false;
	bool easy = false;
};