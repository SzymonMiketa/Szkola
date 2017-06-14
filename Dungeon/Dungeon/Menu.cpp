#include "Menu.h"




Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("DawnLike\\GUI\\a_6x6.ttf"))
	{

	}
	for (int i = 0; i < NUMBER_OF_MENU_OPTIONS; i++)
	{
		menu[i].setFont(font);
	}

	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Start");
	menu[0].setPosition(width / 2 - 100, height / (NUMBER_OF_MENU_OPTIONS + 1) * 1);

	menu[1].setColor(sf::Color::White);
	menu[1].setString("Continue");
	menu[1].setPosition(width / 2 - 100, height / (NUMBER_OF_MENU_OPTIONS + 1) * 2);

	menu[2].setColor(sf::Color::White);
	menu[2].setString("Quit");
	menu[2].setPosition(width / 2 - 100, height / (NUMBER_OF_MENU_OPTIONS + 1) * 3);


	SelectedItem = 0;
	sf::Texture tmp;
	tmp.loadFromFile("DawnLike\\Examples\\Underworld-0.png");
	Background_Texture.push_back(tmp);
	tmp.loadFromFile("DawnLike\\Examples\\Underworld-1.png");
	Background_Texture.push_back(tmp);
	CurrentSprite = 0;
	Background_Sprite.setTexture(Background_Texture[0]);
	T = 0;
	Opened_menu = true;
}

Menu::~Menu()
{
}

void Menu::action(sf::Keyboard::Key k, sf::RenderWindow & window, Level_design * L)
{
	switch (k)
	{
	case sf::Keyboard::Up:
		Up();
		break;
	case sf::Keyboard::Down:
		Down();
		break;
	case sf::Keyboard::Return:
		ClickedMenu(window, L);
		break;
	}
}

void Menu::draw(sf::RenderWindow & window)
{
	T += 0.05;
	if (T >= 1)
	{
		if (CurrentSprite == 0) {
			Background_Sprite.setTexture(Background_Texture[1]);
			CurrentSprite = 1;
		}
		else {
			Background_Sprite.setTexture(Background_Texture[0]);
			CurrentSprite = 0;
		}
		T = 0;
	}
	window.draw(Background_Sprite);
	for (int i = 0; i < NUMBER_OF_MENU_OPTIONS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::Up()
{
	menu[SelectedItem].setColor(sf::Color::White);
	if (SelectedItem == 0)
	{
		SelectedItem = NUMBER_OF_MENU_OPTIONS - 1;
	}
	else
	{
		SelectedItem--;
	}
	menu[SelectedItem].setColor(sf::Color::Red);
}

void Menu::Down()
{
	menu[SelectedItem].setColor(sf::Color::White);
	if (SelectedItem == NUMBER_OF_MENU_OPTIONS - 1)
	{
		SelectedItem = 0;
	}
	else
	{
		SelectedItem++;
	}
	menu[SelectedItem].setColor(sf::Color::Red);
}

void Menu::ClickedMenu(sf::RenderWindow & window, Level_design * L)
{
	try {
		switch (SelectedItem)
		{
		case 0:
			Opened_menu = false;
			L->New_Game();
			break;
		case 1:
			if (L->Game_Ended == true)
			Opened_menu = false;
			L->Game_Ended = false;
			break;
		case 2:
			window.close();
			break;
		}
	}
	catch (string s)
	{
		throw s;
	}
}
