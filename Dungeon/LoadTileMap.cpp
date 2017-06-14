#include "LoadTileMap.h"



LoadTileMap::LoadTileMap(string FileName)
{
	ifstream file(FileName);
	if (file.is_open())
	{
		string tileLocation;
		file >> tileLocation;
		Tiles.loadFromFile(tileLocation);
		Sprite.setTexture(Tiles);
		while (!file.eof())
		{
			string str;
			file >> str;
			char x = str[0], y = str[2];
			if (!isdigit(x) || !isdigit(y))
			{
				tempMap.push_back(sf::Vector2i(-1, -1));
			}
			else
			{
				tempMap.push_back(sf::Vector2i(x - '0', y - '0'));
			}
			if (file.peek() == '\n')
			{
				Map.push_back(tempMap);
				tempMap.clear();
			}
		}
		Map.push_back(tempMap);
	}
}

void LoadTileMap::DrawTileMap(sf::RenderWindow & window)
{
	for (int i = 0; i < Map.size(); i++)
	{
		for (int j = 0; j < Map[i].size(); j++)
		{
			if (Map[i][j].x != -1 && Map[i][j].y != -1)
			{
				Sprite.setPosition(j * 16, i * 16);
				Sprite.setTextureRect(sf::IntRect(Map[i][j].x * 16, Map[i][j].y * 16, 16, 16));
				window.draw(Sprite);
			}
		}
	}
}

void LoadTileMap::ReturnValue(int x, int y, int & tempX, int & tempY)
{
	tempX = Map[x][y].x;
	tempY = Map[x][y].y;
}

int LoadTileMap::ReturnSize()
{
	return Map.size();
}

int LoadTileMap::ReturnSizeI(int i)
{
	return Map[i].size();
}


LoadTileMap::~LoadTileMap()
{
}
