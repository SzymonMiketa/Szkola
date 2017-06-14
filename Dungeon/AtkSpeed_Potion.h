#pragma once
#include "Items.h"
class AtkSpeed_Potion :
	public Items
{
public:
	AtkSpeed_Potion(int x_arg, int y_arg, sf::Texture const& texture);
	void ReturnEffects(Player* P);
	~AtkSpeed_Potion();
};

