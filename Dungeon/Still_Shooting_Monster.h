#pragma once
#include "Enemy.h"
class Still_Shooting_Monster :
	public Enemy
{
public:
	float ReloadSpeed;
	float isReloaded;
	Still_Shooting_Monster(sf::Texture const& texture, sf::Texture const & texture2);
	void update(TileMap & map, Create_objects & o, Audio & audio, int Projectile_R, sf::IntRect k, int which_texture);
	~Still_Shooting_Monster();
};

