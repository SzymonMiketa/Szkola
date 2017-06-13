#include "Boss_1.h"
#include "Create_objects.h"




Boss_1::Boss_1(int x_arg, int y_arg, sf::Texture const& texture, sf::Texture const & texture2, Audio & audio) : Enemy(texture, texture2)
{
	Entity_Sprite.setTexture(Entity_Texture[0]);
	sf::IntRect k = sf::IntRect(2 * 16, 5 * 16, 16, 16);
	frames.push_back(k);
	Entity_Sprite.setTextureRect(k);
	Entity_Sprite.setOrigin(8, 8);
	Entity_Sprite.scale(sf::Vector2f(5.f, 5.f));
	Entity_Sprite.setPosition(y_arg * 16, x_arg * 16); //Bo w mapie x i y s¹ odwrotnie
	TilePositionX = y_arg;
	TilePositionY = x_arg;
	x = y_arg * 16;
	y = x_arg * 16;
	maxhitpoints = 2000;
	hitpoints = 2000;
	speed = 0;
	damage = 20;
	R = 40;
	isReloaded = (rand() % 100);
	isReloaded = isReloaded / 100;
	ReloadSpeed = 0.01;
	buffer.push_back(&audio.buffer[1]);
	exp_given = 5000;
	Projectile_R = 3;
	CurrentFrame = 0;
	
}

void Boss_1::update(TileMap & map, Create_objects & o, Audio & audio)
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
				float tmp = rand() % 10;
				tmp = tmp / 10;
				o.Create_New_Projectile(sf::IntRect(1 * 16, 22 * 16, 16 ,16), x, y, true, Projectile_R, -sin(angle2), -cos(angle2), 0, damage, 1, audio);
				o.Create_New_Projectile(sf::IntRect(3 * 16, 22 * 16, 16, 16), x, y, true, Projectile_R, -sin(angle2) + tmp, -cos(angle2) + tmp, 0, damage, 1, audio);
				tmp = rand() % 10;
				tmp = tmp / 10;
				o.Create_New_Projectile(sf::IntRect(5 * 16, 22 * 16, 16, 16), x, y, true, Projectile_R, -sin(angle2) + tmp, -cos(angle2) + tmp, 0, damage, 1, audio);
				tmp = rand() % 10;
				tmp = tmp / 10;
				o.Create_New_Projectile(sf::IntRect(7 * 16, 22 * 16, 16, 16), x, y, true, Projectile_R, -sin(angle2) + tmp, -cos(angle2) + tmp, 0, damage, 1, audio);
				isReloaded = 0;
				s.setBuffer(*buffer[0]);
				s.play();
			}
		}
	}
	isReloaded += ReloadSpeed;
	Enemy::update_sprite();
}

Boss_1::~Boss_1()
{
}
