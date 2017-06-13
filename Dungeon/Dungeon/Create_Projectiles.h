#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include "Projectiles.h"

using namespace std;

class Create_Projectiles
{
private:
	vector<sf::Texture> Projectile_Textures;
	vector<Projectiles*> Projectiles_list;

public:
	void load_projectile_textures();
	void update_projectiles(TileMap & map);
	void draw_projectiles(sf::RenderWindow & window);
	Create_Projectiles();
	~Create_Projectiles();
};

