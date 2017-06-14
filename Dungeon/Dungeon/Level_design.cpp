#include "Level_design.h"



void Level_design::make_player()
{
	player = new Player("Mage.png", audio);
	player->SetPosition(200, 200);
	Entities.Push_Player(player);
}

Level_design::Level_design()
{
	player = NULL;
	Entities.Load_Monster_Textures();
	Entities.Load_Projectile_Textures();
	Entities.Load_Items_Textures();
	background.loadFromFile("background1.jpg");
	background_s.setTexture(background);
	background_s.setTextureRect(sf::IntRect(106, 0, 640, 480));
	Game_Ended = false;
	ChangedLevel = false;
	map.load_map("Level1.txt");
	map.load(sf::Vector2u(16, 16));
	map2.load_map("Level1.a.txt");
	map2.load(sf::Vector2u(16, 16));
	CurrentLevel = 1;
}


void Level_design::Change_Level()
{
	try {
		if (ChangedLevel)
		{
			switch (CurrentLevel)
			{
			case 1:
				Entities.Create_Monsters("Monsters_Level1.txt");
				Entities.Make_Monsters(audio);
				break;
			case 2:
				Entities.Create_Monsters("Monsters_Level2.txt");
				Entities.Make_Monsters(audio);
				break;
			case 3:
				Entities.Create_Monsters("Monsters_Level3.txt");
				Entities.Make_Monsters(audio);
				break;
			case 4:
				Entities.Create_Monsters("Monsters_Level4.txt");
				Entities.Make_Monsters(audio);
				break;
			case 5:
				Entities.Create_Monsters("Monsters_Level5.txt");
				Entities.Make_Monsters(audio);
				break;
			}
			ChangedLevel = false;
		}
		if(Game_Ended == false)
		if (Entities.Check_Enemy() == false) {
			ChangedLevel = true;
			CurrentLevel++;
		}
	}
	catch (string s)
	{
		throw s;
	}
}

void Level_design::Update_Level(sf::RenderWindow & window)
{
	if (CurrentLevel > 5)
	{
		Player *Pl = dynamic_cast<Player *>(player);
		Pl->Update_GUI();
		Pl->gui.show_victory_screen(window);
		Game_Ended = true;
	}
	bool player_is_dead = true;
	if(Game_Ended == false)
	player_is_dead = Entities.Update_Entities(map, audio);
	window.draw(background_s);
	window.draw(map);
	window.draw(map2);
	Entities.Draw_Entities(window);
	if (player_is_dead == true)
	{
		Player *Pl = dynamic_cast<Player *>(player);
		Pl->gui.show_death_screen(window);
		Game_Ended = true;
		
	}
}

void Level_design::New_Game()
{
	try {
		Entities.delete_objects();
		make_player();
		CurrentLevel = 1;
		ChangedLevel = true;
		Game_Ended = false;
		Change_Level();
	}
	catch (int a)
	{
		throw a;
	}

}


Level_design::~Level_design()
{
	//usuwanie playera jest i tak w destruktorze Create_Monster
}
