#pragma once

#include "Create_objects.h"
#include "Player.h"

class Level_design
{
private:
	Entity * player;
	int CurrentLevel;
	bool ChangedLevel;
	TileMap map;
	TileMap map2;
	Create_objects Entities;
	Audio audio;
	sf::Texture background;
	sf::Sprite background_s;

public:
	bool Game_Ended;
	void make_player();
	Level_design();
	void Change_Level();
	void Update_Level(sf::RenderWindow & window);
	void New_Game();
	~Level_design();
};

