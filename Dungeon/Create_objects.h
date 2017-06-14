#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include <fstream>
#include "Projectiles.h"
#include "Angry_Tree.h"
#include <typeinfo>
#include <iostream>
#include "Audio.h"
#include "Potion.h"
#include "AtkSpeed_Potion.h"
#include "Player.h"
#include "Damage_Potion.h"
#include "Death.h"
#include "Boss_1.h"



using namespace std;

enum monsters { Angry_Tree_e = 1 , Death_e, Boss_1_e};

class Create_objects
{
private:
	vector<sf::Texture> Enemy_Textures;
	vector<vector<int>> Monsters;
	vector<int> MonstersTmp;
	vector<sf::Texture> Projectile_Textures;
	vector<Entity*> Entity_list;
	vector<sf::Texture> Items_Textures;
public:
	Create_objects();
	void Give_Exp(Entity* En);
	void Create_Monsters(string FileName); 
	void Make_Monsters(Audio & audio);  //Chwilowa zmiana z playerem, potem poprawic
	void Push_Player(Entity * player);
	void Create_New_Item(int x, int y, int choice);
	void Load_Monster_Textures();
	void Load_Items_Textures();
	void Load_Projectile_Textures();
	bool Update_Entities(TileMap & map, Audio & audio);
	void Check_Collision(); //Kolizja miêdzy Enitties (Kolizja miedzy Entities a map¹ jest w update() ka¿dego obiektu)
	void Draw_Entities(sf::RenderWindow & window);
	void Create_New_Projectile(sf::IntRect k, float x, float y, bool enemy_projectile, float R, float dx, float dy, int which_texture, int damage, int life, Audio & audio);
	bool Find_Location_Of_Object(const type_info & t, float & x, float & y);
	void delete_objects();
	bool Check_Enemy();
	~Create_objects();
};

