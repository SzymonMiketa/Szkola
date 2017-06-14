#include "Still_Shooting_Monster.h"

#include "Create_objects.h"



Still_Shooting_Monster::Still_Shooting_Monster(sf::Texture const& texture, sf::Texture const & texture2) : Enemy(texture, texture2)
{
}

void Still_Shooting_Monster::update(TileMap & map, Create_objects & o, Audio & audio, int Projectile_R, sf::IntRect k, int which_texture)
{
	if (isReloaded >= 1)
	{
		float x_target, y_target;
		if (o.Find_Location_Of_Object(typeid(Player*), x_target, y_target) == true); //true - znaleziono gracza
		{
			float a = x - x_target;
			float b = y - y_target;
			if (((a) * (a)) + ((b) * (b)) < (R * 40) * (R * 40))  //40 - im wieksze R tym wiekszy zasieg przeciwnika
			{
				float angle2 = M_PI / 2 - (atan2(b, a));
				o.Create_New_Projectile(k, x, y, true, Projectile_R, -sin(angle2), -cos(angle2), which_texture, damage, 1, audio);
				isReloaded = 0;
				s.setBuffer(*buffer[0]);
				s.play();
			}
		}
	}
	isReloaded += ReloadSpeed;
	Enemy::update_sprite();
}



Still_Shooting_Monster::~Still_Shooting_Monster()
{
}
