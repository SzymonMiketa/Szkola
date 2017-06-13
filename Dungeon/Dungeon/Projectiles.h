#pragma once


#include "Entity.h"

class Projectiles : public Entity
{
private:
	sf::Texture Projectile_Texture;
	sf::Sprite Projectile_Sprite;
	bool enemy_projectile;
	int damage;
	sf::Sound s;
public:
	Projectiles(sf::IntRect k, float x, float y, bool enemy_projectile, float R, float dx, float dy, sf::Texture & texture, int damage, int life, Audio & audio);
	void update(TileMap & map, Create_objects & o, Audio & audio);
	void check_collision(TileMap & map);
	void draw(sf::RenderWindow & window);
	const type_info & return_type();
	void HitByProjectile(bool & a, int & b);
	void HittingSomethingP(bool & a, int & b, bool x1);
	~Projectiles();
};

