#include "GUI.h"



void GUI::Set_Sprites(int a, int b, int points_arg)
{
	float tmp = b;
	tmp = tmp / a;
	for (int i = 0; i < 5; i++)
	{
		if (tmp >= 0.2)
		{
			GUI_Sprite[i].setTextureRect(GUI_Frames[0]);
			tmp -= 0.2;
		}
		else if(tmp > 0)
		{
			tmp = tmp / 0.2;
			if (tmp >= 0.75) 
			GUI_Sprite[i].setTextureRect(GUI_Frames[0]);
			else if (tmp >= 0.5)
			GUI_Sprite[i].setTextureRect(GUI_Frames[1]);
			else if (tmp >= 0.25)
			GUI_Sprite[i].setTextureRect(GUI_Frames[2]);
			else if (tmp > 0)
			GUI_Sprite[i].setTextureRect(GUI_Frames[3]);
			else 
			GUI_Sprite[i].setTextureRect(GUI_Frames[4]);
			tmp = 0;
		}	
		else
		{
			GUI_Sprite[i].setTextureRect(GUI_Frames[4]);
		}
	}
	string s = to_string(points_arg);
	points.setString(s);
}

void GUI::draw(sf::RenderWindow & window)
{
	for (auto i : GUI_Sprite)
	{
		window.draw(i);
	}
	window.draw(points);
}

void GUI::show_death_screen(sf::RenderWindow & window)
{
	string tmp = "You got ";
	string tmp2 = " points!";
	string tmp3 = tmp + points.getString() + tmp2;
	points_endgame.setString(tmp3);
	points_endgame.setPosition(220, 200);
	window.draw(Game_Over);
	window.draw(points_endgame);

}

void GUI::show_victory_screen(sf::RenderWindow & window)
{
	string tmp = "You got ";
	string tmp2 = " points!";
	string tmp3 = tmp + points.getString() + tmp2;
	Game_Over.setString("You won!");
	Game_Over.setPosition(150, 100);
	points_endgame.setString(tmp3);
	points_endgame.setPosition(220, 200);
	window.draw(Game_Over);
	window.draw(points_endgame);
}

GUI::GUI()
{
	if (!font.loadFromFile("DawnLike\\GUI\\a_6x6.ttf"))
	{

	}
	points.setFont(font);
	points.setColor(sf::Color::White);
	points.setPosition(100, 0);
	points.setCharacterSize(15);
	points_endgame.setFont(font);
	points_endgame.setColor(sf::Color::White);
	points_endgame.setCharacterSize(15);
	Game_Over.setFont(font);
	Game_Over.setColor(sf::Color::Red);
	Game_Over.setCharacterSize(60);
	Game_Over.setPosition(100, 100);
	Game_Over.setString("Game Over");
	GUI_Texture.loadFromFile("DawnLike\\GUI\\GUI0.png");
	sf::Sprite tmp;
	tmp.setTexture(GUI_Texture);
	for (int i = 0; i < 5; i++)
	{
		GUI_Frames.push_back(sf::IntRect(i * 16, 16, 16, 16));
		GUI_Sprite.push_back(tmp);
	}
	for (int i = 0; i < 5; i++){
		GUI_Sprite[i].setTextureRect(GUI_Frames[0]);
		GUI_Sprite[i].setPosition(i * 16, 0);
	}
}


GUI::~GUI()
{
}
