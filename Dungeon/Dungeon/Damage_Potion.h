
#include "Items.h"
class Damage_Potion :
	public Items
{
public:
	Damage_Potion(int x_arg, int y_arg, sf::Texture const& texture);
	~Damage_Potion();
	void ReturnEffects(Player* P);
};
