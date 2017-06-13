#include "Create_Projectiles.h"



void Create_Projectiles::load_projectile_textures()
{
	sf::Texture tmp;
	tmp.loadFromFile("DawnLike\\Objects\\Effect0.png");
	Projectile_Textures.push_back(tmp);
}


void Create_Projectiles::update_projectiles(TileMap & map)
{
	for (auto i = Projectiles_list.begin(); i != Projectiles_list.end();)
	{
		Projectiles *tmp = *i;
	//	tmp->update(map);
		if (tmp->return_life() < 1)
		{
			i = Projectiles_list.erase(i);
			delete tmp;
		}
		else i++;
	}
}

void Create_Projectiles::draw_projectiles(sf::RenderWindow & window)
{
	for (int i = 0; i < Projectiles_list.size(); i++)
	{
		Projectiles_list[i]->draw(window);
	}
}

Create_Projectiles::Create_Projectiles()
{
}


Create_Projectiles::~Create_Projectiles()
{
}
