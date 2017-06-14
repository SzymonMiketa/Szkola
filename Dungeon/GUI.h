#pragma once

#include "SFML/Graphics.hpp"
#include <vector>

using namespace std;

class GUI
{

public:
	sf::Text points;
	sf::Text Game_Over;
	sf::Text points_endgame;
	sf::Font font;
	vector<sf::IntRect> GUI_Frames;
	sf::Texture GUI_Texture;
	vector<sf::Sprite> GUI_Sprite;
	void Set_Sprites(int a, int b, int points);
	void draw(sf::RenderWindow & window);
	void show_death_screen(sf::RenderWindow & window);
	void show_victory_screen(sf::RenderWindow & window);
	GUI();
	~GUI();
};

