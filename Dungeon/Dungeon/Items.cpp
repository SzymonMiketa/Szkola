#include "Items.h"



Items::Items()
{
}

void Items::draw(sf::RenderWindow & window)
{
	window.draw(Entity_Sprite);
}

void Items::update(TileMap & map, Create_objects & o, Audio & audio)
{
}

const type_info & Items::return_type()
{
	return typeid(this);
}


Items::~Items()
{
}
