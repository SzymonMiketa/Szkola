#pragma once
#include "Entity.h"
#include "Player.h"

class Items :
	public Entity
{
protected:
	sf::Texture Entity_Texture;
	sf::Sprite Entity_Sprite;
public:
	Items();
	void draw(sf::RenderWindow & window);
	void update(TileMap & map, Create_objects & o, Audio & audio);
	const type_info & return_type();
	virtual void ReturnEffects(Player * pl) = 0;
	~Items();
};

