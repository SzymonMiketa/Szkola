#pragma once
#include "Still_Shooting_Monster.h"

class Angry_Tree :
	public Still_Shooting_Monster
{
public:
	int Projectile_R;
	void update(TileMap & map, Create_objects & o, Audio & audio);
	Angry_Tree(int x, int y, sf::Texture const& texture, sf::Texture const & texture2, Audio & audio);
	~Angry_Tree();
};

