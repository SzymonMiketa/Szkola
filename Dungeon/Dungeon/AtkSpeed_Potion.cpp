#include "AtkSpeed_Potion.h"



AtkSpeed_Potion::AtkSpeed_Potion(int x_arg, int y_arg, sf::Texture const & texture)
{
	Entity_Texture = texture;
	Entity_Sprite.setTexture(Entity_Texture);
	Entity_Sprite.setTextureRect(sf::IntRect(96, 0, 16, 16));
	Entity_Sprite.setOrigin(8, 8);
	x = x_arg;
	y = y_arg;
	Entity_Sprite.setPosition(x, y);
	hitpoints = 1;
	R = 5;
}

void AtkSpeed_Potion::ReturnEffects(Player * P)
{
	P->CurrentReloadSpeed += 0.02;
	hitpoints = 0;
}


AtkSpeed_Potion::~AtkSpeed_Potion()
{
}
