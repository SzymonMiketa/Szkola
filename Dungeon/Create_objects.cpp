#include "Create_objects.h"



Create_objects::Create_objects()
{
}

void Create_objects::Give_Exp(Entity * En)
{
	Enemy *p = dynamic_cast<Enemy *>(En);
	for (auto i : Entity_list)
	{
		if (i->return_type() == typeid(Player*))
		{
			Player *Pl = dynamic_cast<Player *>(i);
			Pl->exp += p->exp_given;
			break;
		}
	}
}


void Create_objects::Create_Monsters(string FileName)
{
	MonstersTmp.clear(); //Jezeli wgrywam drugi poziom
	Monsters.clear();
	ifstream file(FileName);
	if (file.is_open())
	{
		while (!file.eof())
		{
			int tmp;
			file >> tmp;
			MonstersTmp.push_back(tmp);
			if (file.peek() == '\n')
			{
				Monsters.push_back(MonstersTmp);
				MonstersTmp.clear();
			}
		}
		Monsters.push_back(MonstersTmp);
	}
	else
	{
		throw FileName;
	}
}

void Create_objects::Make_Monsters(Audio & audio)
{
	for (int i = 0; i < Monsters.size(); i++)
	{
		for (int j = 0; j < Monsters[i].size(); j++)
		{
			switch (Monsters[i][j])
			{
			case Angry_Tree_e:
			{
				Angry_Tree *Enemy_tmp = new Angry_Tree(i, j, Enemy_Textures[0], Enemy_Textures[1], audio); //Klamry bo jakis blad inaczej by byl
				Entity_list.push_back(Enemy_tmp);
			}
				break;
			case Death_e:
			{
				Death *Enemy_tmp = new Death(i, j, Enemy_Textures[2], Enemy_Textures[3], audio);
				Entity_list.push_back(Enemy_tmp);
			}
				break;
			case Boss_1_e:
			{
				Boss_1 *Enemy_tmp = new Boss_1(i, j, Enemy_Textures[4], Enemy_Textures[5], audio);
				Entity_list.push_back(Enemy_tmp);
			}
			break;
		}
		}
	}
}

void Create_objects::Push_Player(Entity * player)
{
	Entity_list.push_back(player);
}

void Create_objects::Create_New_Item(int x, int y, int choice)
{
	if (choice == 0)
	{
		Potion *tmp = new Potion(x, y, Items_Textures[0]);
		Entity_list.push_back(tmp);
	}
	else if (choice == 1)
	{
		AtkSpeed_Potion *tmp = new AtkSpeed_Potion(x, y, Items_Textures[0]);
		Entity_list.push_back(tmp);
	}
	else if (choice == 2)
	{
		Damage_Potion *tmp = new Damage_Potion(x, y, Items_Textures[0]);
		Entity_list.push_back(tmp);
	}
}

void Create_objects::Load_Monster_Textures()
{
	sf::Texture tmp;
	tmp.loadFromFile("DawnLike\\Characters\\Plant0.png");
	Enemy_Textures.push_back(tmp);
	tmp.loadFromFile("DawnLike\\Characters\\Plant1.png");
	Enemy_Textures.push_back(tmp);
	tmp.loadFromFile("DawnLike\\Characters\\Undead0.png");
	Enemy_Textures.push_back(tmp);
	tmp.loadFromFile("DawnLike\\Characters\\Undead1.png");
	Enemy_Textures.push_back(tmp);
	tmp.loadFromFile("DawnLike\\Characters\\Elemental1.png");
	Enemy_Textures.push_back(tmp);
	tmp.loadFromFile("DawnLike\\Characters\\Elemental1.png");
	Enemy_Textures.push_back(tmp);
}

void Create_objects::Load_Items_Textures()
{

	sf::Texture tmp;
	tmp.loadFromFile("DawnLike\\Items\\Potion.png");
	Items_Textures.push_back(tmp);
}

void Create_objects::Load_Projectile_Textures()
{
	sf::Texture tmp;
	tmp.loadFromFile("DawnLike\\Objects\\Effect0.png");
	Projectile_Textures.push_back(tmp);
}

bool Create_objects::Update_Entities(TileMap & map, Audio & audio)
{
	bool player_is_dead = false;
	Check_Collision();
	for (int i = 0; i < Entity_list.size(); i++)
	{
		Entity *tmp = Entity_list[i];
		tmp->update(map, *this, audio);
	}
	for (auto i = Entity_list.begin(); i != Entity_list.end();)
	{
		Entity *tmp = *i;
		if (tmp->return_life() < 1)
		{
			if (tmp->return_type() == typeid(Enemy*)) Give_Exp(tmp);
			if (tmp->return_type() == typeid(Player*))
			{
				player_is_dead = true;
				i++;
			}
			else
			{
				i = Entity_list.erase(i);
				delete tmp;
			}
		}
		else i++;
	}
	return player_is_dead;
}

void Create_objects::Check_Collision()
{
	for (auto a : Entity_list)
	{
		for (auto b : Entity_list)
		{
			if (a->check_collision(b)) {
				if (a->return_type() == typeid(Enemy*) && b->return_type() == typeid(Projectiles*))
				{
					bool x;
					int y;
					bool x1 = true; //Pocisk przechodzi przez wroga
					b->HittingSomethingP(x, y, x1);
					a->HitByProjectile(x, y);
				}		
				else if (a->return_type() == typeid(Player*) && b->return_type() == typeid(Enemy*))
				{

				}
				else if (a->return_type() == typeid(Player*) && b->return_type() == typeid(Projectiles*))
				{
					bool x;
					int y;
					bool x1 = false; //Pocisk przechodzi przez Playera
					b->HittingSomethingP(x, y, x1);
					a->HitByProjectile(x, y);
				}
				else if (a->return_type() == typeid(Player*) && b->return_type() == typeid(Items*))
				{
					int a1;
					float b1, c1;
					Player *Pl = dynamic_cast<Player *>(a);
					Items *It = dynamic_cast<Items *>(b);
					It->ReturnEffects(Pl);
					Pl->BuffedByPotion();
				}
			}
		}
	}
}

void Create_objects::Draw_Entities(sf::RenderWindow & window)
{
	for (auto i : Entity_list)
	{
		i->draw(window);
	}
}

void Create_objects::Create_New_Projectile(sf::IntRect k, float x, float y, bool enemy_projectile, float R, float dx, float dy, int which_texture, int damage, int life, Audio & audio)
{
	Projectiles *tmp = new Projectiles(k, x, y, enemy_projectile, R, dx, dy, Projectile_Textures[which_texture], damage, life, audio);
	Entity_list.push_back(tmp);
}

bool Create_objects::Find_Location_Of_Object(const type_info & t, float & x, float & y)
{
	for (auto i : Entity_list)
	{
		if (i->return_type() == t)
		{
			i->return_location(x, y);
			return true;
		}
	}
	return false;
}

void Create_objects::delete_objects()
{
	for (auto i = Entity_list.begin(); i != Entity_list.end();)
	{
		Entity *tmp = *i;
		i = Entity_list.erase(i);
		delete tmp;
	}
	Entity_list.clear();
}

bool Create_objects::Check_Enemy()
{
	for (auto i : Entity_list)
	{
		if (i->return_type() == typeid(Enemy*))
		{
			return true;
		}
	}
	return false;
}


Create_objects::~Create_objects()
{
	for (auto i = Entity_list.begin(); i != Entity_list.end();)
	{
		Entity *tmp = *i;
		i = Entity_list.erase(i);
		delete tmp;
	}
	Entity_list.clear();
}
