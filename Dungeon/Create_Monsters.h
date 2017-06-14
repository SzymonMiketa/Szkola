#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <fstream>
#include "Angry_Tree.h"

using namespace std;

//enum monsters { Angry_Tree_e = 1 };

class Create_Monsters
{
private:
	vector<sf::Texture> Enemy_Textures;
	vector<vector<int>> Monsters;
	vector<int> MonstersTmp;

public:
	vector<Enemy*> Enemy_list;
	Create_Monsters(string FileName);
	void update_monsters();
	void load_monster_textures();
	void draw(sf::RenderWindow & window);
	~Create_Monsters();
};

