#include "Potion.h"



Potion::Potion(int x_arg, int y_arg, sf::Texture const& texture)
{
	Entity_Texture = texture;
	Entity_Sprite.setTexture(Entity_Texture);
	Entity_Sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	Entity_Sprite.setOrigin(8, 8);
	x = x_arg;
	y = y_arg;
	Entity_Sprite.setPosition(x, y);
	hitpoints = 1;
	R = 5;
}

void Potion::ReturnEffects(Player * P)
{
	P->hitpoints += 30;
	hitpoints = 0;
}


Potion::~Potion()
{
}
