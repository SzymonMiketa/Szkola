#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


class LoadTileMap
{
private:
	std::vector<std::vector<sf::Vector2i>> Map;
	std::vector<sf::Vector2i> tempMap;
	sf::Texture Tiles;
	sf::Sprite Sprite;
public:
	LoadTileMap(string FileName);
	void DrawTileMap(sf::RenderWindow & window);
	void ReturnValue(int x, int y, int & tempX, int & tempY);
	int ReturnSize();
	int ReturnSizeI(int i);
	~LoadTileMap();
};

