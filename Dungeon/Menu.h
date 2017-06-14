#pragma once
#include "SFML/Graphics.hpp"
#include "Level_design.h"

#define NUMBER_OF_MENU_OPTIONS 4

using namespace std;

class Menu
{
private:
	float T;
	int CurrentSprite;
	int SelectedItem;
	sf::Font font;
	sf::Text menu[NUMBER_OF_MENU_OPTIONS];
	vector<sf::Texture> Background_Texture;
	sf::Sprite Background_Sprite;

public:
	bool Opened_menu;
	Menu(float width, float height);
	~Menu();
	void action(sf::Keyboard::Key k, sf::RenderWindow & window, Level_design * L);
	void draw(sf::RenderWindow & window);
	void Up();
	void Down();
	void ClickedMenu(sf::RenderWindow & window, Level_design * L);
	

};

