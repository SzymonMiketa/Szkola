#include "Create_Monsters.h"



Create_Monsters::Create_Monsters(string FileName)
{
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
}

void Create_Monsters::update_monsters()
{
}



void Create_Monsters::load_monster_textures()
{
	sf::Texture tmp;
	tmp.loadFromFile("DawnLike\\Characters\\Plant0.png");
	Enemy_Textures.push_back(tmp);
	tmp.loadFromFile("DawnLike\\Characters\\Plant1.png");
	Enemy_Textures.push_back(tmp);
}

void Create_Monsters::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < Enemy_list.size(); i++)
	{
		Enemy_list[i]->draw(window);
	}
}


Create_Monsters::~Create_Monsters()
{
}
