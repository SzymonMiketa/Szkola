#include "Projectiles.h"



Projectiles::Projectiles(sf::IntRect k, float x_arg, float y_arg, bool enemy_projectile_arg, float R_arg, float dx_arg, float dy_arg, sf::Texture & texture, int damage_arg, int life_arg, Audio & audio)
{
	Projectile_Texture = texture;
	Projectile_Sprite.setTexture(Projectile_Texture);
	Projectile_Sprite.setTextureRect(k);
	Projectile_Sprite.setOrigin(8, 8);
	Projectile_Sprite.setPosition(x_arg, y_arg);
	x = x_arg;
	y = y_arg;
	R = R_arg;
	enemy_projectile = enemy_projectile_arg;
	dx = dx_arg;
	dy = dy_arg;
	damage = damage_arg;
	maxhitpoints = life_arg;
	hitpoints = life_arg;

}

void Projectiles::update(TileMap & map, Create_objects & o, Audio & audio)
{
	x += dx;
	y += dy;
	Projectile_Sprite.setPosition(x, y);
	TilePositionX = x / 16;
	TilePositionY = y / 16;
	check_collision(map);
}


void Projectiles::check_collision(TileMap & map)
{
	int temp = map.ReturnValue(TilePositionX, TilePositionY);
	if (temp == 63 || temp == 64 || temp == 84 || temp == 105 || temp == 106 || temp == 108 || temp == 87 || temp == 66 || temp == 65 || temp == 107)
	{
		hitpoints = 0;
	}
}

void Projectiles::draw(sf::RenderWindow & window)
{
	window.draw(Projectile_Sprite);
}

const type_info & Projectiles::return_type()
{
	return typeid(this);
}

void Projectiles::HitByProjectile(bool & a, int & b)
{
}


void Projectiles::HittingSomethingP(bool & a, int & b, bool x1) //x1 = true, pocisk przechodzi przez przeciwnika, false - przez gracza
{
	a = enemy_projectile;
	b = damage;
	if (a != x1)
	{
		hitpoints--;
	}
	
}


Projectiles::~Projectiles()
{
}
