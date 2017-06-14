#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include "Player.h"
#include <cstdlib>
#include "Menu.h"
#include "TileMap.h"
#include "Enemy.h"
#include "Angry_Tree.h"
#include "Create_objects.h"
#include "Audio.h"
#include "Level_design.h"
using namespace std;





int main()
{
	//Fps
	sf::Clock clock;
	float lastTime = 0;
	sf::Text fps_t;
	sf::Font font;
	font.loadFromFile("DawnLike\\GUI\\a_6x6.ttf");
	fps_t.setFont(font);
	fps_t.setCharacterSize(15);
	fps_t.setPosition(480, 0);
	srand(time(NULL));
	//Tworzenie okna
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Dobra Giera");
	//Ustawianie widoku
	sf::View VisibleArea(sf::FloatRect(0, 0, 640, 480));
	Menu menu(VisibleArea.getSize().x, VisibleArea.getSize().y);
	window.setView(VisibleArea);
	//Chowanie myszy
	window.setMouseCursorVisible(false);
	//Ustawienie limit fps
	window.setFramerateLimit(60);
	//Tworzenie poziomu
	Level_design *Game = new Level_design();
	while (window.isOpen())
	{
		try {
			Game->Change_Level();
			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					if (menu.Opened_menu == true)
					{
						menu.action(event.key.code, window, Game);
					}
					else
					{
						switch (event.key.code)
						{
						case sf::Keyboard::Escape:
							menu.Opened_menu = true;
							Game->Game_Ended = true;
							break;
						case sf::Keyboard::Down:
							break;
						case sf::Keyboard::Return:
							if (Game->Game_Ended == true)
							{
								menu.Opened_menu = true;
							}
							break;
						}
					}
				}
			}
			//Liczenie fps
			float currentTime = clock.restart().asSeconds();
			float fps = 1.f / lastTime;
			lastTime = currentTime;
			string s = to_string(fps);
			fps_t.setString(s);
			//
			window.clear();
			if (menu.Opened_menu == false)
			{
				Game->Update_Level(window);
			}
			else if (menu.Opened_menu == true)
			{
				menu.draw(window);
			}
			window.draw(fps_t);
			window.display();
		}
		catch (string s)
		{
			cout << "Nie udalo sie zaladowac pliku o nazwie: " << s << '\n' << "Prosze sprobowac ponownie skopiowac pliki" << endl;
			system("pause");
			break;
		}
	}
	delete Game;
}