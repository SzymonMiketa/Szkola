#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

#include "Entity.h"
//#include "Create_objects.h"
#include "GUI.h"

using namespace std;

class Create_objects;



class Player : public Entity
{
private:
	sf::Sprite PlayerSprite;
	sf::Texture PlayerTexture;
	vector<sf::IntRect> Frames;
	float CurrentFrame;
	float CurrentWeaponSpeed;
	float isReloaded;
	sf::Sound s2;
public:
	int CurrentDamage;
	float CurrentReloadSpeed;
	GUI gui;
	int exp;
	Player(string FileName, Audio & audio);
	~Player();
	void Update_GUI();
	bool check_collision(TileMap & map);
	void action(TileMap & map);
	void draw(sf::RenderWindow & window);
	void SetPosition(int x, int y);
	void shoot(Create_objects & o, Audio & audio);
	void update(TileMap & map, Create_objects & o, Audio & audio);
	void HitByProjectile(bool & a, int & b);
	void BuffedByPotion();
	const type_info & return_type();
	void show_death_screen();

};