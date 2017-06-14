#pragma once
#include "Items.h"
class Potion :
	public Items
{
public:
	Potion(int x_arg, int y_arg, sf::Texture const& texture);
	void ReturnEffects(Player* P);
	~Potion();
};

