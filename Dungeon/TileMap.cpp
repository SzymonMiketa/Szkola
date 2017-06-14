#include "TileMap.h"



void TileMap::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	{
		// apply the transform
		states.transform *= getTransform();

		// apply the tileset texture
		states.texture = &m_tileset;

		// draw the vertex array
		target.draw(m_vertices, states);
	}
}

int TileMap::load_map(string FileName)
{
	Map.clear();
	tempMap.clear(); //Jezeli wgrywa sie kolejny poziom
	ifstream file(FileName);
	if (file.is_open())
	{
		string tileLocation;
		file >> tileLocation;
		// load the tileset texture
		if (!m_tileset.loadFromFile(tileLocation))
			return false;
		while (!file.eof())
		{
			int tmp;
			file >> tmp;
			tempMap.push_back(tmp);
			if (file.peek() == '\n')
			{
				Map.push_back(tempMap);
				tempMap.clear();
			}
		}
		Map.push_back(tempMap);
	}
}

bool TileMap::load(sf::Vector2u tileSize)
{
	{
		// resize the vertex array to fit the level size
		m_vertices.setPrimitiveType(sf::Quads);
		m_vertices.resize(Map.size() * Map[0].size() * 4);

		// populate the vertex array, with one quad per tile
		for (unsigned int i = 0; i < Map.size(); ++i)
			for (unsigned int j = 0; j < Map[i].size(); ++j)
			{
				// get the current tile number
				int tileNumber = Map[i][j];

				if (tileNumber != -1) {
					// find its position in the tileset texture
					int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
					int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

					// get a pointer to the current tile's quad
					sf::Vertex* quad = &m_vertices[(i + j * Map.size()) * 4];

					// define its 4 corners
					quad[0].position = sf::Vector2f(j * tileSize.x, i * tileSize.y);
					quad[1].position = sf::Vector2f((j + 1) * tileSize.x, i * tileSize.y);
					quad[2].position = sf::Vector2f((j + 1) * tileSize.x, (i + 1) * tileSize.y);
					quad[3].position = sf::Vector2f(j * tileSize.x, (i + 1) * tileSize.y);

					// define its 4 texture coordinates
					quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
					quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
					quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
					quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
				}
			}

		return true;
	}
}

int TileMap::ReturnValue(int x, int y)
{
	return Map[y][x];
}

int TileMap::ReturnSize()
{
	return Map.size();
}

int TileMap::ReturnSizeI(int i)
{
	return Map[i].size();
}


