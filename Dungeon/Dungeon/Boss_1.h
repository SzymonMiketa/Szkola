#pragma once
#include "Enemy.h"
#include "Player.h"

class Boss_1 :
	public Enemy
{
private:
	float ReloadSpeed;
	float isReloaded;
	int Projectile_R;
public:
	Boss_1(int x_arg, int y_arg, sf::Texture const& texture, sf::Texture const & texture2, Audio & audio);
	void update(TileMap & map, Create_objects & o, Audio & audio);
	~Boss_1();
};

