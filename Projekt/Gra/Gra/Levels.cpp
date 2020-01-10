#include "pch.h"
#include "Levels.h"


Levels::~Levels()
{
}

Levels::Levels(int difficulty)
{
	//0 - Easy, 1 - Normal, 2 - Hard, 3 - Insane
	switch (difficulty)
	{
	case 0://level easy

		HP = 1000;
		playerDamage = 50;
		easy = true;
		break;
	case 1://level normal
		HP = 500;
		break;
	case 2://level hard
		HP = 500;
		break;
		playerDamage = 5;
	case 3://level inseane
		HP = 250;
		playerDamage = 5;
		inseane = true;
		break;
	}
}

int Levels::Level1()
{
	Clock clock;
	RenderWindow window(VideoMode(900, 900), "LVL 1 ", Style::Close | Style::Titlebar);
	//View view(Vector2f(0.0f, 0.0f), Vector2f(800.0f, 800.0f));
	//Gracz

	Texture playerTexture;
	playerTexture.loadFromFile("../../SpriteSheetsS/DerRitter.png");

	Texture levelUpTexture;
	levelUpTexture.loadFromFile("../../SpriteSheetsS/Door.png");

	Texture Wall1;
	Wall1.loadFromFile("../../SpriteSheetsS/W.png");

	Texture Wall2;
	Wall2.loadFromFile("../../SpriteSheetsS/W2.png");

	Player player(&playerTexture, Vector2u(10, 15), HP /*(hp zmienia sie dla poziomow trudnosci)*/, 0.10f, 310.0f);

	//level up door

	//LevelUp Door1(&playerTexture, Vector2u(10, 15), 0.25f, 857, 680);
	LevelUp Door1(&levelUpTexture, Vector2u(6, 1), 0.10f, 857, 680);

	bool open = false;
	int CET = 0;
	//czy przeciwnik istnieje
	bool enemy1 = true, enemy2 = true, enemy3 = true, enemy4 = true, enemy5 = true;
	//bool isNotAttacking = 1;//0 - player not attacking, 1 - player attacking (CET - ColliderEnemyType)


	//Przeciwnicy
	Texture skeletonTexture;
	skeletonTexture.loadFromFile("../../SpriteSheetsS/Skeleton.png");

	Enemy skeleton1(&skeletonTexture, Vector2u(9, 4), 0.25f, 450.0f, 450.0f, 120.0f);
	Enemy skeleton2(&skeletonTexture, Vector2u(9, 4), 0.25f, 250.0f, 70.0f, 210.0f);
	Enemy skeleton3(&skeletonTexture, Vector2u(9, 4), 0.25f, 550.0f, 800.0f, 80.0f);
	Enemy skeleton4(&skeletonTexture, Vector2u(9, 4), 0.25f, 60.0f, 200.0f, 200.0f);
	Enemy skeleton5(&skeletonTexture, Vector2u(9, 4), 0.25f, 140.0f, 500.0f, 210.0f);

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
	cout << skeleton1.speedMulti;


	//Przeszkody i inne objekty fizyczne (MAPA_POZIOMOW)
	Platform platform1(&Wall2, Vector2f(320.f, 19.0f), Vector2f(500.0f, 120.0f));
	Platform platform2(&Wall1, Vector2f(19.f, 350.0f), Vector2f(340.0f, 400.0f));
	Platform platform3(&Wall1, Vector2f(19.f, 600.0f), Vector2f(170.0f, 250.0f));
	Platform platform4(&Wall1, Vector2f(19.f, 410.0f), Vector2f(670.0f, 370.0f));
	Platform platform5(&Wall2, Vector2f(200.f, 19.f), Vector2f(170.0f, 670.0f));
	Platform platform6(&Wall1, Vector2f(19.f, 200.0f), Vector2f(218.0f, 770.0f));
	Platform platform7(&Wall2, Vector2f(70.f, 130.0f), Vector2f(780.0f, 665.0f));
	Platform platform8(&Wall1, Vector2f(120.f, 50.0f), Vector2f(860.0f, 625.0f));

	//granice
	Border top(Vector2f(900.0f, 105.0f), Vector2f(450.0f, -51.0f));
	Border left(Vector2f(105.0f, 900.0f), Vector2f(-51.0f, 450.0f));
	Border right(Vector2f(105.0f, 900.0f), Vector2f(951.0f, 450.0f));
	Border bottom(Vector2f(900.0f, 105.0f), Vector2f(450.0f, 951.0f));

	cout << "HP: " << HP << endl << "DMG: " << playerDamage << endl;

	Vector2u size = window.getSize();
	unsigned int width = size.x;//szerokosc
	unsigned int height = size.y;//wysokosc
	cout << "szerokosc=" << width << "\n";
	cout << "wysokosc=" << height << "\n";
	cout << "Starting Hp: " << player.ReadHp() << endl;
	while (window.isOpen())
	{
		window.setFramerateLimit(144);//set teh framerate

		float deltaTime = 0.0f;
		deltaTime = clock.restart().asSeconds();

		Event ev;
		while (window.pollEvent(ev))
		{
			switch (ev.type)
			{
			case Event::Closed:
				window.close();
				break;

				/*case Event::TextEntered:
					if (evnt.text.unicode < 128)
					{
						printf("%c", evnt.text.unicode);
					}
					break;
				 */
			case Event::KeyPressed:
				if (ev.key.code == Keyboard::Escape)
					window.close();
				break;
			}
		}

		//poruszanie
		player.Update(deltaTime);

		Door1.doorAnimation(open, deltaTime);

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
			skeleton5.Movement(2, 90.0f, 470.0f, deltaTime);

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
				cout << endl << "Hp: " << player.ReadHp();
				break;
			case 2:
				cout << "enemy1 hit" << endl;
				skeleton1.HpLoss(playerDamage);
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
				cout << endl << "Hp: " << player.ReadHp();
				break;
			case 2:
				cout << "enemy2 hit" << endl;
				skeleton2.HpLoss(playerDamage);
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
				cout << endl << "Hp: " << player.ReadHp();
				break;
			case 2:
				cout << "enemy3 hit" << endl;
				skeleton3.HpLoss(playerDamage);
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
				cout << endl << "Hp: " << player.ReadHp();
				break;
			case 2:
				cout << "enemy4 hit" << endl;
				skeleton4.HpLoss(playerDamage);
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
				cout << endl << "Hp: " << player.ReadHp();
				break;
			case 2:
				cout << "enemy5 hit" << endl;
				skeleton5.HpLoss(playerDamage);
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
		//sad ending
		/*if (player.ReadHp() < 1)
		{

			system("cls");
			cout << "U DEAD!";
			return 666;

		}*/

		//first condition
		if (enemy1 == false && enemy2 == false && enemy3 == false && enemy4 == false && enemy5 == false)
		{
			open = true;

		}
		//level complited
		if (open == true)
			if (Door1.GetCollider().CheckColision(player.GetCollider(), 0, 0, 0) == 0)
			{
				//add more stuf
				return score;

			}

		//ryswoanie
		window.clear(Color(70, 70, 70)); //clear old frame	

		//Rysowanie mapy

		Door1.Draw(window);

		platform1.Draw(window);
		platform2.Draw(window);
		platform3.Draw(window);
		platform4.Draw(window);
		platform5.Draw(window);
		platform6.Draw(window);
		platform7.Draw(window);
		platform8.Draw(window);

		right.Draw(window);
		left.Draw(window);
		bottom.Draw(window);
		top.Draw(window);

		player.Draw(window);

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

		window.display();
	}
	return 0;
}

int Levels::Level2()
{
	return 0;
}

int Levels::Level3()
{
	return 0;
}
