#include "Angry_Tree.h"

#include "Create_objects.h"

void Angry_Tree::update(TileMap & map, Create_objects & o, Audio & audio)
{
	Still_Shooting_Monster::update(map, o, audio, Projectile_R, sf::IntRect(0, 368, 16, 16), 0);
	if (hitpoints <= 0)
	{
		int a = rand() % 2;
		if (a == 0)
		{
			int b = rand() % 3;
			if(b == 0)
			o.Create_New_Item(x, y, 0);
			else if (b == 1)
			o.Create_New_Item(x, y, 1);
			else if (b == 2)
			o.Create_New_Item(x, y, 2);
		}
	}
	Enemy::update_sprite();
}

Angry_Tree::Angry_Tree(int x_arg, int y_arg, sf::Texture const& texture, sf::Texture const & texture2, Audio & audio) : Still_Shooting_Monster(texture, texture2){
	Entity_Sprite.setTexture(Entity_Texture[0]);
	sf::IntRect k = sf::IntRect(2 * 16, 0, 16, 16);
	frames.push_back(k);
	Entity_Sprite.setTextureRect(k);
	Entity_Sprite.setOrigin(8, 8);
	Entity_Sprite.setPosition(y_arg * 16, x_arg * 16); //Bo w mapie x i y s¹ odwrotnie
	TilePositionX = y_arg;
	TilePositionY = x_arg;
	x = y_arg * 16;
	y = x_arg * 16;
	maxhitpoints = 100;
	hitpoints = 100;
	speed = 0;
	damage = 7;
	R = 10;
	isReloaded = (rand() % 100);
	isReloaded = isReloaded / 100;
	ReloadSpeed = 0.01;
	buffer.push_back(&audio.buffer[1]);
	exp_given = 50;
	Projectile_R = 3;
	CurrentFrame = 0;
}




Angry_Tree::~Angry_Tree()
{
}
