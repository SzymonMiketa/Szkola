#pragma once
#include "SFML/Graphics.hpp"
#include <fstream>
using namespace std;

class TileMap : public sf::Drawable, public sf::Transformable
{
private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	std::vector<std::vector<int>> Map;
	std::vector<int> tempMap;
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
public:
	int load_map(string FileName);
	bool load(sf::Vector2u tileSize);
	int ReturnValue(int x, int y);
	int ReturnSize();
	int ReturnSizeI(int i);


};