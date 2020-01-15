#include "pch.h"
#include "Levels.h"


Levels::~Levels()
{
}


void Levels::saveGame(bool enemy1, bool enemy2, bool enemy3, bool enemy4, bool enemy5, int HP, bool open, int gameDifficulty, int PosX, int PosY, bool keyVisible, int currentLevel)
{
	Save.open("../../Save/GameSave.txt", ios::out);

	Save << enemy1 << endl;
	Save << enemy2 << endl;
	Save << enemy3 << endl;
	Save << enemy4 << endl;
	Save << enemy5 << endl;
	Save << HP << endl;
	Save << open << endl;
	Save << gameDifficulty << endl;
	Save << PosX << endl;
	Save << PosY << endl;
	Save << keyVisible << endl;
	Save << currentLevel << endl;

	Save.close();
}


int Levels::returnLevel()
{
	return currentLevel;
}

Levels::Levels(int difficulty, int option, bool Continued)
{
	switch (option)//default -> 60
	{
	case 1:
		framerate = 30;
		break;
	case 2:
		framerate = 144;
		break;
	}
	if (Continued == false)//fixed with saving
	{
		gameDifficulty = difficulty;
	}
	else
	{
		Save.open("../../Save/GameSave.txt", ios::in);
		if (Save.good() == false)
		{
			cout << "Plik nie istnieje";
		}
		Save >> enemy1;
		Save >> enemy2;
		Save >> enemy3;
		Save >> enemy4;
		Save >> enemy5;
		Save >> HP;
		Save >> open;
		Save >> gameDifficulty;
		Save >> PosX;
		Save >> PosY;
		Save >> keyVisible;
		Save >> currentLevel;

		Save.close();
	}
	//0 - Easy, 1 - Normal, 2 - Hard, 3 - Insane
	switch (gameDifficulty)
	{		
	case 0://level easy
		i = 0;
		easy = true;
		break;
	case 1://level normal
		i = 1;
		break;
	case 2://level hard
		i = 2;
		break;
	case 3://level inseane
		i = 3;
		inseane = true;
		break;
	}
	if (Continued == false)
		HP = Dif[i].HP;
}

int Levels::Level1()
{
	//cout << "GameDiff" << gameDifficulty << endl;
	Clock clock;
	Clock deadClock;
	RenderWindow window(VideoMode(900, 1000), "Lower Dungeon ", Style::Close | Style::Titlebar);
	currentLevel = 1;

	SureMenu Sure1(900, 1000);
	Texture Background;
	Background.loadFromFile("../../SpriteSheetsS/LVL1/Background.JPG");
	Sprite S1; //background
	S1.setTexture(Background);
	S1.setScale(1.56f, 2.34f);
	S1.setPosition(0.0f, 100.0f);

	Texture heartPic;
	heartPic.loadFromFile("../../SpriteSheetsS/Heart.png");
	Enemy heart(&heartPic, Vector2u(5, 1), 0.15f, 400.0f, 50.0f, 0.0f);

	Texture F1Help;
	F1Help.loadFromFile("../../SpriteSheetsS/Help.png");

	Texture Key;
	Key.loadFromFile("../../SpriteSheetsS/Key.png");

	Texture playerTexture;
	playerTexture.loadFromFile("../../SpriteSheetsS/DerRitter.png");

	Texture levelUpTexture;
	levelUpTexture.loadFromFile("../../SpriteSheetsS/LVL1/Door.png");

	Texture Wall1;
	Wall1.loadFromFile("../../SpriteSheetsS/LVL1/W.png");

	Texture Wall2;
	Wall2.loadFromFile("../../SpriteSheetsS/LVL1/W2.png");

	Texture Wall3;
	Wall3.loadFromFile("../../SpriteSheetsS/LVL1/W3.png");

	Texture Wall4;
	Wall4.loadFromFile("../../SpriteSheetsS/LVL1/W4.png");

	Texture Wall5;
	Wall5.loadFromFile("../../SpriteSheetsS/LVL1/W5.png");

	Texture Bar;
	Bar.loadFromFile("../../SpriteSheetsS/LVL1/SkullBar.png");
	Player player(&playerTexture, Vector2u(10, 15), HP /*(hp zmienia sie dla poziomow trudnosci)*/, 0.10f, 310.0f, PosX, PosY);

	//Przeciwnicy
	Texture skeletonTexture;
	skeletonTexture.loadFromFile("../../SpriteSheetsS/LVL1/Skeleton.png");
	//level up door

	LevelUp Door1(&levelUpTexture, Vector2u(6, 1), 0.10f, 857, 780);

	Enemy skeleton1(&skeletonTexture, Vector2u(9, 4), 0.25f, 450.0f, 550.0f, 120.0f);
	Enemy skeleton2(&skeletonTexture, Vector2u(9, 4), 0.25f, 250.0f, 170.0f, 210.0f);
	Enemy skeleton3(&skeletonTexture, Vector2u(9, 4), 0.25f, 550.0f, 900.0f, 80.0f);
	Enemy skeleton4(&skeletonTexture, Vector2u(9, 4), 0.25f, 60.0f, 300.0f, 200.0f);
	Enemy skeleton5(&skeletonTexture, Vector2u(9, 4), 0.25f, 140.0f, 600.0f, 210.0f);

	if (inseane == true)
	{
		skeleton1.speedMulti = 2.0;
		skeleton2.speedMulti = 2.0;
		skeleton3.speedMulti = 2.0;
		skeleton4.speedMulti = 2.0;
		skeleton5.speedMulti = 2.0;
	}
	if (easy == true)
	{
		skeleton1.speedMulti = 0.75;
		skeleton2.speedMulti = 0.75;
		skeleton3.speedMulti = 0.75;
		skeleton4.speedMulti = 0.75;
		skeleton5.speedMulti = 0.75;
	}

	//Przeszkody i inne objekty fizyczne (MAPA_POZIOMOW)
	Platform platform1(&Wall2, Vector2f(320.f, 19.0f), Vector2f(500.0f, 220.0f));
	Platform platform2(&Wall1, Vector2f(19.f, 350.0f), Vector2f(340.0f, 500.0f));
	Platform platform3(&Wall3, Vector2f(19.f, 570.0f), Vector2f(170.0f, 380.0f));
	Platform platform4(&Wall1, Vector2f(19.f, 410.0f), Vector2f(651.0f, 431.0f));
	Platform platform5(&Wall2, Vector2f(200.f, 19.0f), Vector2f(170.0f, 820.0f));
	Platform platform6(&Wall1, Vector2f(19.f, 200.0f), Vector2f(218.0f, 920.0f));
	Platform platform7(&Wall5, Vector2f(70.f, 130.0f), Vector2f(780.0f, 765.0f));
	Platform platform8(&Wall4, Vector2f(120.f, 50.0f), Vector2f(860.0f, 725.0f));

	//granice
	Border top(Vector2f(900.0f, 105.0f), Vector2f(450.0f, 51.0f), 0);
	Border left(Vector2f(105.0f, 900.0f), Vector2f(-51.0f, 550.0f), 0);
	Border right(Vector2f(105.0f, 900.0f), Vector2f(951.0f, 550.0f), 0);
	Border bottom(Vector2f(900.0f, 105.0f), Vector2f(450.0f, 1051.0f), 0);

	Border sureBorder(Vector2f(500, 300), Vector2f(475, 500), 1);
	Platform f1help(&F1Help, Vector2f(800, 800), Vector2f(450, 550));
	Platform key(&Key, Vector2f(30, 30), Vector2f(160, 950));

	//SkullBar
	Platform skulBar(&Bar, Vector2f(900.0f, 20.0f), Vector2f(450.0f, 93.0f));


	Vector2u size = window.getSize();
	unsigned int width = size.x;//szerokosc
	unsigned int height = size.y;//wysokosc

	while (window.isOpen())
	{

		Event LvL1;
		while (window.pollEvent(LvL1))
		{
			if ((LvL1.type == sf::Event::KeyPressed) && (LvL1.key.code == sf::Keyboard::Escape))
			{
				EscapeQuestion = true;
				QuestionPause = false;
			}
			if ((LvL1.type == sf::Event::KeyPressed) && (LvL1.key.code == sf::Keyboard::F1))
			{
				QuestionPause = true;
			}
			if ((LvL1.type == sf::Event::KeyPressed) && (LvL1.key.code == sf::Keyboard::F2))
			{
				QuestionPause = false;
			}
			if ((LvL1.type == sf::Event::KeyPressed) && (LvL1.key.code == sf::Keyboard::F4))
			{
				saveGame(enemy1, enemy2, enemy3, enemy4, enemy5, player.ReadHp(), open, gameDifficulty, player.GetPosition().x, player.GetPosition().y, keyVisible, currentLevel);
			}

			//Wyjscie za pomoca Esc 
			if (EscapeQuestion == true)
			{
				if (LvL1.type == Event::KeyPressed)
				{
					if (LvL1.key.code == Keyboard::D || LvL1.key.code == Keyboard::Right)
					{
						Sure1.GOLEFT();
					}

					if (LvL1.key.code == Keyboard::A || LvL1.key.code == Keyboard::Left)
					{
						Sure1.goRight();
					}
					if (LvL1.key.code == Keyboard::Enter && Sure1.getSelectedItem() == 0 || LvL1.key.code == Keyboard::Space && Sure1.getSelectedItem() == 0)
					{
						saveGame(enemy1, enemy2, enemy3, enemy4, enemy5, player.ReadHp(), open, gameDifficulty, player.GetPosition().x, player.GetPosition().y, keyVisible, currentLevel);
						window.close();
					}
					if (LvL1.key.code == Keyboard::Enter && Sure1.getSelectedItem() == 1 || LvL1.key.code == Keyboard::Space && Sure1.getSelectedItem() == 1)
					{
						EscapeQuestion = false;
					}
				}
			}
		}
		window.setFramerateLimit(framerate);//set teh framerate

		float deltaTime = 0.0f;
		deltaTime = clock.restart().asSeconds();

		//sposób zderzania sie
		//granice mapy
		bottom.GetCollider().CheckColision(player.GetCollider(), 1.0f, 0, 0);
		right.GetCollider().CheckColision(player.GetCollider(), 1.0f, 0, 0);
		left.GetCollider().CheckColision(player.GetCollider(), 1.0f, 0, 0);
		top.GetCollider().CheckColision(player.GetCollider(), 1.0f, 0, 0);

		platform2.GetCollider().CheckColision(player.GetCollider(), 1, 0, 0);
		platform1.GetCollider().CheckColision(player.GetCollider(), 1, 0, 0);
		platform3.GetCollider().CheckColision(player.GetCollider(), 1, 0, 0);
		platform4.GetCollider().CheckColision(player.GetCollider(), 1, 0, 0);
		platform5.GetCollider().CheckColision(player.GetCollider(), 1, 0, 0);
		platform6.GetCollider().CheckColision(player.GetCollider(), 1, 0, 0);
		platform7.GetCollider().CheckColision(player.GetCollider(), 1, 0, 0);
		platform8.GetCollider().CheckColision(player.GetCollider(), 1, 0, 0);

		//changes if player is attacking	
		if (player.isAttacking == true)
			CET = 2;
		else
			CET = 1;
		//colisions and damage 
		{
			//collision with enemy1
			if (enemy1 == true)
			{
				//fixed throwback
				if (CET != 1)
					CET = 3;
				switch (skeleton1.GetCollider().CheckColision(player.GetCollider(), 1.0f, CET, 1))
				{
				case 1:
					player.HpLoss(10);
					break;
				case 2:
					*skeleton1.HpIndicator -= Dif[i].playerDamage;
					break;
				}
			}
			//collision with enemy2
			if (enemy2 == true)
			{
				//fixed throwback
				if (CET != 1)
					CET = 3;
				switch (skeleton2.GetCollider().CheckColision(player.GetCollider(), 1.0f, CET, 1))
				{
				case 1:
					player.HpLoss(10);
					break;
				case 2:
					*skeleton2.HpIndicator -= Dif[i].playerDamage;
					break;
				}
			}

			//collision with enemy1
			if (enemy3 == true)
			{
				//fixed throwback
				if (CET != 1)
					CET = 3;
				switch (skeleton3.GetCollider().CheckColision(player.GetCollider(), 1.0f, CET, 1))
				{
				case 1:
					player.HpLoss(10);
					break;
				case 2:
					*skeleton3.HpIndicator -= Dif[i].playerDamage;
					break;
				}
			}

			//collision with enemy1
			if (enemy4 == true)
			{
				//fixed throwback
				if (CET != 1)
					CET = 4;
				switch (skeleton4.GetCollider().CheckColision(player.GetCollider(), 1.0f, CET, 1))
				{
				case 1:
					player.HpLoss(10);
					break;
				case 2:
					*skeleton4.HpIndicator -= Dif[i].playerDamage;
					break;
				}
			}

			//collision with enemy1

			if (enemy5 == true)
			{
				//fixed throwback
				if (CET != 1)
					CET = 4;
				switch (skeleton5.GetCollider().CheckColision(player.GetCollider(), 1.0f, CET, 1))
				{
				case 1:
					player.HpLoss(10);
					break;
				case 2:
					*skeleton5.HpIndicator -= Dif[i].playerDamage;
					break;
				}

			}
			//enemy killing
			if (skeleton1.ReadHp() < 1)
				enemy1 = false;
			if (skeleton2.ReadHp() < 1)
				enemy2 = false;
			if (skeleton3.ReadHp() < 1)
				enemy3 = false;
			if (skeleton4.ReadHp() < 1)
				enemy4 = false;
			if (skeleton5.ReadHp() < 1)
				enemy5 = false;
		}
		//sad ending
		if (player.ReadHp() < 1)
			alive = false;

		if (key.GetCollider().CheckColision(player.GetCollider(), 0, 0, 0) == 0)
		{
			keyVisible = false;
		}

		//first condition
		if (enemy1 == false && enemy2 == false && enemy3 == false && enemy4 == false && enemy5 == false && keyVisible == false)
		{
			open = true;
		}
		//level complited
		if (open == true)
			if (Door1.GetCollider().CheckColision(player.GetCollider(), 0, 0, 0) == 0)
			{
				//add more stuf :)
				window.close();

				enemy1 = true,
					enemy2 = true,
					enemy3 = true,
					enemy4 = true,
					enemy5 = true;

				keyVisible = true;
				open = false;
				PosX = 500;
				PosY = 500;
				Level2();
			}

		//poruszanie
		//update
		if (QuestionPause == false && EscapeQuestion == false)
		{
			Door1.doorAnimation(open, deltaTime);

			player.Update(deltaTime);

			heart.Animate(deltaTime);
			//start musi byæ mniejszy ni¿ end
			if (enemy1)
				skeleton1.Movement(3, 400.0f, 600.0f, deltaTime);
			if (enemy2)
				skeleton2.Movement(1, 310.0f, 620.0f, deltaTime);
			if (enemy3)
				skeleton3.Movement(1, 370.0f, 760.0f, deltaTime);
			if (enemy4)
				skeleton4.Movement(2, 150.0f, 820.0f, deltaTime);
			if (enemy5)
				skeleton5.Movement(2, 190.0f, 470.0f, deltaTime);
		}
		if (alive == false)
		{
			Time deadTime;
			deadTime = deadClock.getElapsedTime();
			deadClock.restart();
			if (deadTime.asMilliseconds() > 1500)
			{
				return 0;
			}
		}

	

		//hp Animation (hp value update)
		Sure1.showHp(player.ReadHp());
		//ryswoanie
		{

			window.clear(); //clear old frame	
			window.draw(S1);

			//Rysowanie mapy

			if (keyVisible)
				key.Draw(window);

			right.Draw(window);
			left.Draw(window);
			bottom.Draw(window);
			top.Draw(window);

			Door1.Draw(window);
			platform4.Draw(window);
			platform1.Draw(window);
			platform2.Draw(window);
			platform3.Draw(window);
			platform5.Draw(window);
			platform7.Draw(window);
			platform7.Draw(window);
			platform8.Draw(window);
			platform6.Draw(window);


			player.Draw(window);
			heart.Draw(window);

			if (enemy1)
				skeleton1.Draw(window);
			if (enemy2)
				skeleton2.Draw(window);
			if (enemy3)
				skeleton3.Draw(window);
			if (enemy4)
				skeleton4.Draw(window);
			if (enemy5)
				skeleton5.Draw(window);

			skulBar.Draw(window);

			if (QuestionPause == true)
			{
				f1help.Draw(window);
			}
			if (EscapeQuestion == true)
			{
				sureBorder.Draw(window);
				Sure1.draw(window);
			}

			if (alive == false)
				Sure1.drawDead(window);
			/*if (alive == false)
			{
				Sleep(1000);

				return 0;
			}*/

			window.draw(Sure1.hpPlease());

			window.display();
		}
	}

	return 0;
}

int Levels::Level2()
{
	Clock clock;
	Clock deadClock;
	RenderWindow window(VideoMode(900, 1000), "Medium Dungeon ", Style::Close | Style::Titlebar);
	//enemy1 = true,enemy2 = true,	enemy3 = true,	enemy4 = true,	enemy5 = true;
	currentLevel = 2;

	SureMenu Sure1(900, 1000);
	Texture Background;
	Background.loadFromFile("../../SpriteSheetsS/LVL2/Background.JPG");
	Sprite S1; //background
	S1.setTexture(Background);
	S1.setScale(1.0f, 1.0f);
	S1.setPosition(0.0f, 100.0f);

	Texture heartPic;
	heartPic.loadFromFile("../../SpriteSheetsS/Heart.png");
	Enemy heart(&heartPic, Vector2u(5, 1), 0.15f, 400.0f, 50.0f, 0.0f);

	Texture F1Help;
	F1Help.loadFromFile("../../SpriteSheetsS/Help.png");

	Texture Key;
	Key.loadFromFile("../../SpriteSheetsS/Key.png");

	Texture playerTexture;
	playerTexture.loadFromFile("../../SpriteSheetsS/DerRitter.png");

	Texture levelUpTexture;
	levelUpTexture.loadFromFile("../../SpriteSheetsS/LVL1/Door.png");

	Texture Wall1;
	Wall1.loadFromFile("../../SpriteSheetsS/LVL2/W.png");

	Texture Wall2;
	Wall2.loadFromFile("../../SpriteSheetsS/LVL2/W1.png");

	Texture Bar;
	Bar.loadFromFile("../../SpriteSheetsS/LVL2/SkullBar.png");

	Player player(&playerTexture, Vector2u(10, 15), Dif[i].HP /*(hp zmienia sie dla poziomow trudnosci)*/, 0.10f, 310.0f, PosX, PosY);

	//Przeciwnicy
	Texture skeletonTexture;
	skeletonTexture.loadFromFile("../../SpriteSheetsS/LVL1/Skeleton.png");
	//level up door

	LevelUp Door1(&levelUpTexture, Vector2u(6, 1), 0.10f, 500, 145);

	Enemy skeleton1(&skeletonTexture, Vector2u(9, 4), 0.25f, 700.0f, 750.0f, 120.0f);
	Enemy skeleton2(&skeletonTexture, Vector2u(9, 4), 0.25f, 250.0f, 150.0f, 210.0f);
	Enemy skeleton3(&skeletonTexture, Vector2u(9, 4), 0.25f, 550.0f, 910.0f, 80.0f);
	Enemy skeleton4(&skeletonTexture, Vector2u(9, 4), 0.25f, 60.0f, 300.0f, 200.0f);
	Enemy skeleton5(&skeletonTexture, Vector2u(9, 4), 0.25f, 640.0f, 530.0f, 110.0f);
	if (inseane == true)
	{
		skeleton1.speedMulti = 2.0;
		skeleton2.speedMulti = 2.0;
		skeleton3.speedMulti = 2.0;
		skeleton4.speedMulti = 2.0;
		skeleton5.speedMulti = 2.0;
	}
	if (easy == true)
	{
		skeleton1.speedMulti = 0.75;
		skeleton2.speedMulti = 0.75;
		skeleton3.speedMulti = 0.75;
		skeleton4.speedMulti = 0.75;
		skeleton5.speedMulti = 0.75;
	}

	//Przeszkody i inne objekty fizyczne (MAPA_POZIOMOW)
	Platform platform1(&Wall1, Vector2f(420.f, 19.0f), Vector2f(350.0f, 220.0f));
	Platform platform2(&Wall2, Vector2f(19.f, 130.0f), Vector2f(551.0f, 150.0f));
	Platform platform3(&Wall2, Vector2f(19.f, 370.0f), Vector2f(150.0f, 395.0f));
	Platform platform4(&Wall2, Vector2f(19.f, 410.0f), Vector2f(551.0f, 600.0f));
	Platform platform5(&Wall1, Vector2f(340.f, 19.0f), Vector2f(730.0f, 620.0f));
	Platform platform6(&Wall1, Vector2f(380.f, 19.0f), Vector2f(180.0f, 850.0f));


	//granice
	Border top(Vector2f(900.0f, 105.0f), Vector2f(450.0f, 51.0f), 0);
	Border left(Vector2f(105.0f, 900.0f), Vector2f(-51.0f, 550.0f), 0);
	Border right(Vector2f(105.0f, 900.0f), Vector2f(951.0f, 550.0f), 0);
	Border bottom(Vector2f(900.0f, 105.0f), Vector2f(450.0f, 1051.0f), 0);

	Border sureBorder(Vector2f(500, 300), Vector2f(475, 500), 1);
	Platform f1help(&F1Help, Vector2f(800, 800), Vector2f(450, 550));
	Platform key(&Key, Vector2f(30, 30), Vector2f(60, 935));

	//SkullBar
	Platform skulBar(&Bar, Vector2f(900.0f, 20.0f), Vector2f(450.0f, 93.0f));

	Vector2u size = window.getSize();
	unsigned int width = size.x;//szerokosc
	unsigned int height = size.y;//wysokosc

	while (window.isOpen())
	{

		Event LvL1;
		while (window.pollEvent(LvL1))
		{
			if ((LvL1.type == sf::Event::KeyPressed) && (LvL1.key.code == sf::Keyboard::Escape))
			{
				EscapeQuestion = true;
				QuestionPause = false;
			}
			if ((LvL1.type == sf::Event::KeyPressed) && (LvL1.key.code == sf::Keyboard::F1))
			{
				QuestionPause = true;
			}
			if ((LvL1.type == sf::Event::KeyPressed) && (LvL1.key.code == sf::Keyboard::F2))
			{
				QuestionPause = false;
			}
			if ((LvL1.type == sf::Event::KeyPressed) && (LvL1.key.code == sf::Keyboard::F4))
			{
				saveGame(enemy1, enemy2, enemy3, enemy4, enemy5, player.ReadHp(), open, gameDifficulty, player.GetPosition().x, player.GetPosition().y, keyVisible, currentLevel);
			}

			//Wyjscie za pomoca Esc 
			if (EscapeQuestion == true)
			{
				if (LvL1.type == Event::KeyPressed)
				{
					if (LvL1.key.code == Keyboard::D || LvL1.key.code == Keyboard::Right)
					{
						Sure1.GOLEFT();
					}

					if (LvL1.key.code == Keyboard::A || LvL1.key.code == Keyboard::Left)
					{
						Sure1.goRight();
					}
					if (LvL1.key.code == Keyboard::Enter && Sure1.getSelectedItem() == 0 || LvL1.key.code == Keyboard::Space && Sure1.getSelectedItem() == 0)
					{
						saveGame(enemy1, enemy2, enemy3, enemy4, enemy5, player.ReadHp(), open, gameDifficulty, player.GetPosition().x, player.GetPosition().y, keyVisible, currentLevel);
						window.close();
					}
					if (LvL1.key.code == Keyboard::Enter && Sure1.getSelectedItem() == 1 || LvL1.key.code == Keyboard::Space && Sure1.getSelectedItem() == 1)
					{
						EscapeQuestion = false;
					}
				}
			}
		}
		window.setFramerateLimit(framerate);//set teh framerate

		float deltaTime = 0.0f;
		deltaTime = clock.restart().asSeconds();

		//sposób zderzania sie

		//granice mapy
		bottom.GetCollider().CheckColision(player.GetCollider(), 1.0f, 0, 0);
		right.GetCollider().CheckColision(player.GetCollider(), 1.0f, 0, 0);
		left.GetCollider().CheckColision(player.GetCollider(), 1.0f, 0, 0);
		top.GetCollider().CheckColision(player.GetCollider(), 1.0f, 0, 0);

		platform2.GetCollider().CheckColision(player.GetCollider(), 1, 0, 0);
		platform1.GetCollider().CheckColision(player.GetCollider(), 1, 0, 0);
		platform3.GetCollider().CheckColision(player.GetCollider(), 1, 0, 0);
		platform4.GetCollider().CheckColision(player.GetCollider(), 1, 0, 0);
		platform5.GetCollider().CheckColision(player.GetCollider(), 1, 0, 0);
		platform6.GetCollider().CheckColision(player.GetCollider(), 1, 0, 0);


		//changes if player is attacking	
		if (player.isAttacking == true)
			CET = 2;
		else
			CET = 1;
		//colisions and damage 
		{
			//collision with enemy1
			if (enemy1 == true)
			{
				//fixed throwback
				if (CET != 1)
					CET = 3;
				switch (skeleton1.GetCollider().CheckColision(player.GetCollider(), 1.0f, CET, 1))
				{
				case 1:
					player.HpLoss(10);
					break;
				case 2:
					*skeleton1.HpIndicator -= Dif[i].playerDamage;
					break;
				}
			}
			//collision with enemy2
			if (enemy2 == true)
			{
				//fixed throwback
				if (CET != 1)
					CET = 3;
				switch (skeleton2.GetCollider().CheckColision(player.GetCollider(), 1.0f, CET, 1))
				{
				case 1:
					player.HpLoss(10);
					break;
				case 2:
					*skeleton2.HpIndicator -= Dif[i].playerDamage;
					break;
				}
			}

			//collision with enemy1

			if (enemy3 == true)
			{
				//fixed throwback
				if (CET != 1)
					CET = 3;
				switch (skeleton3.GetCollider().CheckColision(player.GetCollider(), 1.0f, CET, 1))
				{
				case 1:
					player.HpLoss(10);
					break;
				case 2:
					*skeleton3.HpIndicator -= Dif[i].playerDamage;
					break;
				}
			}

			//collision with enemy1

			if (enemy4 == true)
			{
				//fixed throwback
				if (CET != 1)
					CET = 4;
				switch (skeleton4.GetCollider().CheckColision(player.GetCollider(), 1.0f, CET, 1))
				{
				case 1:
					player.HpLoss(10);
					break;
				case 2:
					*skeleton4.HpIndicator -= Dif[i].playerDamage;
					break;
				}
			}

			//collision with enemy1

			if (enemy5 == true)
			{
				//fixed throwback
				if (CET != 1)
					CET = 4;
				switch (skeleton5.GetCollider().CheckColision(player.GetCollider(), 1.0f, CET, 1))
				{
				case 1:
					player.HpLoss(10);
					break;
				case 2:
					*skeleton5.HpIndicator -= Dif[i].playerDamage;
					break;
				}
			}
			//enemy killing
			if (skeleton1.ReadHp() < 1)
				enemy1 = false;
			if (skeleton2.ReadHp() < 1)
				enemy2 = false;
			if (skeleton3.ReadHp() < 1)
				enemy3 = false;
			if (skeleton4.ReadHp() < 1)
				enemy4 = false;
			if (skeleton5.ReadHp() < 1)
				enemy5 = false;
		}
		//sad ending
		if (player.ReadHp() < 1)
			alive = false;

		if (key.GetCollider().CheckColision(player.GetCollider(), 0, 0, 0) == 0)
		{
			keyVisible = false;
		}

		//first condition
		if (enemy1 == false && enemy2 == false && enemy3 == false && enemy4 == false && enemy5 == false && keyVisible == false)
		{
			open = true;
		}
		//level complited
		if (open == true)
			if (Door1.GetCollider().CheckColision(player.GetCollider(), 0, 0, 0) == 0)
			{
				window.close();

					enemy1 = true,
					enemy2 = true,
					enemy3 = true,
					enemy4 = true,
					enemy5 = true;

				keyVisible = true;
				open = false;
				Level3();
			}

		//poruszanie
		//update
		if (QuestionPause == false && EscapeQuestion == false)
		{
			Door1.doorAnimation(open, deltaTime);

			player.Update(deltaTime);

			heart.Animate(deltaTime);
			if (enemy1)
				skeleton1.Movement(3, 660.0f, 850.0f, deltaTime);
			if (enemy2)
				skeleton2.Movement(1, 110.0f, 520.0f, deltaTime);
			if (enemy3)
				skeleton3.Movement(1, 70.0f, 520.0f, deltaTime);
			if (enemy4)
				skeleton4.Movement(2, 150.0f, 620.0f, deltaTime);
			if (enemy5)
				skeleton5.Movement(1, 590.0f, 870.0f, deltaTime);
		}

		Sure1.showHp(player.ReadHp());
		//ryswoanie
		{
			window.clear(); //clear old frame	
			window.draw(S1);

			//Rysowanie mapy

			if (keyVisible)
				key.Draw(window);

			right.Draw(window);
			left.Draw(window);
			bottom.Draw(window);
			top.Draw(window);

			Door1.Draw(window);

			platform1.Draw(window);
			platform2.Draw(window);
			platform3.Draw(window);
			platform4.Draw(window);
			platform5.Draw(window);
			platform6.Draw(window);


			player.Draw(window);
			heart.Draw(window);

			if (enemy1)
				skeleton1.Draw(window);
			if (enemy2)
				skeleton2.Draw(window);
			if (enemy3)
				skeleton3.Draw(window);
			if (enemy4)
				skeleton4.Draw(window);
			if (enemy5)
				skeleton5.Draw(window);

			skulBar.Draw(window);

			if (QuestionPause == true)
			{
				f1help.Draw(window);
			}
			if (EscapeQuestion == true)
			{
				sureBorder.Draw(window);
				Sure1.draw(window);
			}
			if (alive == false)
			{
				/*Sure1.drawDead(window);
				Sleep(1000);*/

				return 0;
			}

			window.draw(Sure1.hpPlease());

			window.display();
		}
	}

	return 0;
}

int Levels::Level3()
{
	Clock clock;
	Clock deadClock;
	RenderWindow window(VideoMode(900, 1000), "Upper Dungeon ", Style::Close | Style::Titlebar);
	currentLevel = 3;

	SureMenu Sure1(900, 1000);
	Texture Background;
	Background.loadFromFile("../../SpriteSheetsS/LVL3/Background.JPG");
	Sprite S1; //background
	S1.setTexture(Background);
	S1.setScale(1.0f, 1.0f);
	S1.setPosition(0.0f, 100.0f);

	Texture heartPic;
	heartPic.loadFromFile("../../SpriteSheetsS/Heart.png");
	Enemy heart(&heartPic, Vector2u(5, 1), 0.15f, 400.0f, 50.0f, 0.0f);

	Texture F1Help;
	F1Help.loadFromFile("../../SpriteSheetsS/Help.png");

	Texture Key;
	Key.loadFromFile("../../SpriteSheetsS/Key.png");

	Texture playerTexture;
	playerTexture.loadFromFile("../../SpriteSheetsS/DerRitter.png");

	Texture levelUpTexture;
	levelUpTexture.loadFromFile("../../SpriteSheetsS/LVL1/Door.png");

	Texture Wall1;
	Wall1.loadFromFile("../../SpriteSheetsS/LVL3/W.png");

	Texture Wall2;
	Wall2.loadFromFile("../../SpriteSheetsS/LVL3/W1.png");

	Texture Bar;
	Bar.loadFromFile("../../SpriteSheetsS/LVL3/SkullBar.png");

	Player player(&playerTexture, Vector2u(10, 15), Dif[i].HP /*(hp zmienia sie dla poziomow trudnosci)*/, 0.10f, 310.0f, PosX, PosY);

	//Przeciwnicy
	Texture skeletonTexture;
	skeletonTexture.loadFromFile("../../SpriteSheetsS/LVL1/Skeleton.png");
	//level up door

	LevelUp Door1(&levelUpTexture, Vector2u(6, 1), 0.10f, 500, 145);

	Enemy skeleton1(&skeletonTexture, Vector2u(9, 4), 0.25f, 700.0f, 750.0f, 120.0f);
	Enemy skeleton2(&skeletonTexture, Vector2u(9, 4), 0.25f, 250.0f, 150.0f, 210.0f);
	Enemy skeleton3(&skeletonTexture, Vector2u(9, 4), 0.25f, 550.0f, 910.0f, 80.0f);
	Enemy skeleton4(&skeletonTexture, Vector2u(9, 4), 0.25f, 60.0f, 300.0f, 200.0f);
	Enemy skeleton5(&skeletonTexture, Vector2u(9, 4), 0.25f, 640.0f, 530.0f, 110.0f);
	if (inseane == true)
	{
		skeleton1.speedMulti = 2.0;
		skeleton2.speedMulti = 2.0;
		skeleton3.speedMulti = 2.0;
		skeleton4.speedMulti = 2.0;
		skeleton5.speedMulti = 2.0;
	}
	if (easy == true)
	{
		skeleton1.speedMulti = 0.75;
		skeleton2.speedMulti = 0.75;
		skeleton3.speedMulti = 0.75;
		skeleton4.speedMulti = 0.75;
		skeleton5.speedMulti = 0.75;
	}

	//Przeszkody i inne objekty fizyczne (MAPA_POZIOMOW)
	Platform platform1(&Wall1, Vector2f(620.f, 19.0f), Vector2f(440.0f, 260.0f));
	Platform platform2(&Wall2, Vector2f(19.f, 330.0f), Vector2f(551.0f, 550.0f));
	Platform platform3(&Wall1, Vector2f(270.0f, 19.0f), Vector2f(270.0f, 395.0f));
	Platform platform5(&Wall1, Vector2f(340.f, 19.0f), Vector2f(370.0f, 622.0f));
	Platform platform6(&Wall1, Vector2f(380.f, 19.0f), Vector2f(250.0f, 850.0f));

	//granice
	Border top(Vector2f(900.0f, 105.0f), Vector2f(450.0f, 51.0f), 0);
	Border left(Vector2f(105.0f, 900.0f), Vector2f(-51.0f, 550.0f), 0);
	Border right(Vector2f(105.0f, 900.0f), Vector2f(951.0f, 550.0f), 0);
	Border bottom(Vector2f(900.0f, 105.0f), Vector2f(450.0f, 1051.0f), 0);

	Border sureBorder(Vector2f(500, 300), Vector2f(475, 500), 1);
	Platform f1help(&F1Help, Vector2f(800, 800), Vector2f(450, 550));
	Platform key(&Key, Vector2f(30, 30), Vector2f(60, 935));

	//SkullBar
	Platform skulBar(&Bar, Vector2f(900.0f, 20.0f), Vector2f(450.0f, 93.0f));

	Vector2u size = window.getSize();
	unsigned int width = size.x;//szerokosc
	unsigned int height = size.y;//wysokosc

	while (window.isOpen())
	{

		Event LvL1;
		while (window.pollEvent(LvL1))
		{
			if ((LvL1.type == sf::Event::KeyPressed) && (LvL1.key.code == sf::Keyboard::Escape))
			{
				EscapeQuestion = true;
				QuestionPause = false;
			}
			if ((LvL1.type == sf::Event::KeyPressed) && (LvL1.key.code == sf::Keyboard::F1))
			{
				QuestionPause = true;
			}
			if ((LvL1.type == sf::Event::KeyPressed) && (LvL1.key.code == sf::Keyboard::F2))
			{
				QuestionPause = false;
			}
			if ((LvL1.type == sf::Event::KeyPressed) && (LvL1.key.code == sf::Keyboard::F4))
			{
				saveGame(enemy1, enemy2, enemy3, enemy4, enemy5, player.ReadHp(), open, gameDifficulty, player.GetPosition().x, player.GetPosition().y, keyVisible, currentLevel);
			}

			//Wyjscie za pomoca Esc 
			if (EscapeQuestion == true)
			{
				if (LvL1.type == Event::KeyPressed)
				{
					if (LvL1.key.code == Keyboard::D || LvL1.key.code == Keyboard::Right)
					{
						Sure1.GOLEFT();
					}

					if (LvL1.key.code == Keyboard::A || LvL1.key.code == Keyboard::Left)
					{
						Sure1.goRight();
					}
					if (LvL1.key.code == Keyboard::Enter && Sure1.getSelectedItem() == 0 || LvL1.key.code == Keyboard::Space && Sure1.getSelectedItem() == 0)
					{
						saveGame(enemy1, enemy2, enemy3, enemy4, enemy5, player.ReadHp(), open, gameDifficulty, player.GetPosition().x, player.GetPosition().y, keyVisible, currentLevel);
						window.close();
					}
					if (LvL1.key.code == Keyboard::Enter && Sure1.getSelectedItem() == 1 || LvL1.key.code == Keyboard::Space && Sure1.getSelectedItem() == 1)
					{
						EscapeQuestion = false;
					}
				}
			}
		}
		window.setFramerateLimit(framerate);//set teh framerate

		float deltaTime = 0.0f;
		deltaTime = clock.restart().asSeconds();

		//sposób zderzania sie

		//granice mapy
		bottom.GetCollider().CheckColision(player.GetCollider(), 1.0f, 0, 0);
		right.GetCollider().CheckColision(player.GetCollider(), 1.0f, 0, 0);
		left.GetCollider().CheckColision(player.GetCollider(), 1.0f, 0, 0);
		top.GetCollider().CheckColision(player.GetCollider(), 1.0f, 0, 0);

		platform2.GetCollider().CheckColision(player.GetCollider(), 1, 0, 0);
		platform1.GetCollider().CheckColision(player.GetCollider(), 1, 0, 0);
		platform3.GetCollider().CheckColision(player.GetCollider(), 1, 0, 0);
		platform5.GetCollider().CheckColision(player.GetCollider(), 1, 0, 0);
		platform6.GetCollider().CheckColision(player.GetCollider(), 1, 0, 0);

		//changes if player is attacking	
		if (player.isAttacking == true)
			CET = 2;
		else
			CET = 1;
		//colisions and damage 
		{
			//collision with enemy1
			if (enemy1 == true)
			{
				//fixed throwback
				if (CET != 1)
					CET = 3;
				switch (skeleton1.GetCollider().CheckColision(player.GetCollider(), 1.0f, CET, 1))
				{
				case 1:
					player.HpLoss(10);
					break;
				case 2:
					*skeleton1.HpIndicator -= Dif[i].playerDamage;
					break;
				}
			}
			//collision with enemy2
			if (enemy2 == true)
			{
				//fixed throwback
				if (CET != 1)
					CET = 3;
				switch (skeleton2.GetCollider().CheckColision(player.GetCollider(), 1.0f, CET, 1))
				{
				case 1:
					player.HpLoss(10);
					break;
				case 2:
					*skeleton2.HpIndicator -= Dif[i].playerDamage;
					break;
				}
			}

			//collision with enemy1

			if (enemy3 == true)
			{
				//fixed throwback
				if (CET != 1)
					CET = 3;
				switch (skeleton3.GetCollider().CheckColision(player.GetCollider(), 1.0f, CET, 1))
				{
				case 1:
					player.HpLoss(10);
					break;
				case 2:
					*skeleton3.HpIndicator -= Dif[i].playerDamage;
					break;
				}
			}

			//collision with enemy1

			if (enemy4 == true)
			{
				//fixed throwback
				if (CET != 1)
					CET = 4;
				switch (skeleton4.GetCollider().CheckColision(player.GetCollider(), 1.0f, CET, 1))
				{
				case 1:
					player.HpLoss(10);
					break;
				case 2:
					*skeleton4.HpIndicator -= Dif[i].playerDamage;
					break;
				}
			}

			//collision with enemy1

			if (enemy5 == true)
			{
				//fixed throwback
				if (CET != 1)
					CET = 4;
				switch (skeleton5.GetCollider().CheckColision(player.GetCollider(), 1.0f, CET, 1))
				{
				case 1:
					player.HpLoss(10);
					break;
				case 2:
					*skeleton5.HpIndicator -= Dif[i].playerDamage;
					break;
				}
			}
			//enemy killing
			if (skeleton1.ReadHp() < 1)
				enemy1 = false;
			if (skeleton2.ReadHp() < 1)
				enemy2 = false;
			if (skeleton3.ReadHp() < 1)
				enemy3 = false;
			if (skeleton4.ReadHp() < 1)
				enemy4 = false;
			if (skeleton5.ReadHp() < 1)
				enemy5 = false;
		}
		//sad ending
		if (player.ReadHp() < 1)
			alive = false;

		if (key.GetCollider().CheckColision(player.GetCollider(), 0, 0, 0) == 0)
		{
			keyVisible = false;
		}

		//first condition
		if (enemy1 == false && enemy2 == false && enemy3 == false && enemy4 == false && enemy5 == false && keyVisible == false)
		{
			open = true;
		}
		//level complited
		if (open == true)
			if (Door1.GetCollider().CheckColision(player.GetCollider(), 0, 0, 0) == 0)
			{
				window.close();

				enemy1 = true,
					enemy2 = true,
					enemy3 = true,
					enemy4 = true,
					enemy5 = true;

				keyVisible = true;
				open = false;
				displayTurh = true;
				Level3();
			}

		//poruszanie
		//update
		if (QuestionPause == false && EscapeQuestion == false)
		{
			Door1.doorAnimation(open, deltaTime);

			player.Update(deltaTime);

			heart.Animate(deltaTime);
			if (enemy1)
				skeleton1.Movement(3, 660.0f, 850.0f, deltaTime);
			if (enemy2)
				skeleton2.Movement(1, 110.0f, 520.0f, deltaTime);
			if (enemy3)
				skeleton3.Movement(1, 70.0f, 520.0f, deltaTime);
			if (enemy4)
				skeleton4.Movement(2, 150.0f, 620.0f, deltaTime);
			if (enemy5)
				skeleton5.Movement(1, 590.0f, 870.0f, deltaTime);
		}

		if (alive == false)
		{
			Time deadTime;
			deadTime = deadClock.getElapsedTime();
			deadClock.restart();
			if (deadTime.asMilliseconds() > 1500)
			{
				return 0;
			}
		}

		Sure1.showHp(player.ReadHp());
		//ryswoanie
		{

			window.clear(); //clear old frame	
			window.draw(S1);

			//Rysowanie mapy

			if (keyVisible)
				key.Draw(window);

			right.Draw(window);
			left.Draw(window);
			bottom.Draw(window);
			top.Draw(window);

			Door1.Draw(window);

			platform1.Draw(window);
			platform2.Draw(window);
			platform3.Draw(window);
			platform5.Draw(window);
			platform6.Draw(window);

			player.Draw(window);
			heart.Draw(window);

			if (enemy1)
				skeleton1.Draw(window);
			if (enemy2)
				skeleton2.Draw(window);
			if (enemy3)
				skeleton3.Draw(window);
			if (enemy4)
				skeleton4.Draw(window);
			if (enemy5)
				skeleton5.Draw(window);

			skulBar.Draw(window);

			if (QuestionPause == true)
			{
				f1help.Draw(window);
			}
			if (EscapeQuestion == true)
			{
				sureBorder.Draw(window);
				Sure1.draw(window);
			}
			if (alive == false)
			{
				/*Sure1.drawDead(window);
				Sleep(1000);*/

				return 0;
			}
			if (displayTurh == true)
				Sure1.Truth(window);

			window.draw(Sure1.hpPlease());

			window.display();
		}
	}
	return 0;
}
