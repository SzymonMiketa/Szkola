#include "Damage_Potion.h"





Damage_Potion::Damage_Potion(int x_arg, int y_arg, sf::Texture const & texture)
{
	Entity_Texture = texture;
	Entity_Sprite.setTexture(Entity_Texture);
	Entity_Sprite.setTextureRect(sf::IntRect(2 * 16, 1 * 16, 16, 16));
	Entity_Sprite.setOrigin(8, 8);
	x = x_arg;
	y = y_arg;
	Entity_Sprite.setPosition(x, y);
	hitpoints = 1;
	R = 5;
}

Damage_Potion::~Damage_Potion()
{
}

void Damage_Potion::ReturnEffects(Player * P)
{
	P->CurrentDamage += 2;
	hitpoints = 0;
}

