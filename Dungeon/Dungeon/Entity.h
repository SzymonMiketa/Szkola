#pragma once


#include "SFML/Graphics.hpp"
#include "TileMap.h"
#include <typeinfo>
#include <iostream>
#include "Audio.h"
#include <cstdlib>
#include <cmath>

#define M_PI 3.14159265358979323846

class Create_objects;

class Entity
{
protected:
	int maxhitpoints;
	float speed;
	int TilePositionX;
	int TilePositionY;
	float dx;
	float dy;
	float x;
	float y;
	float R; //Do kolizji
	vector<sf::SoundBuffer*> buffer;
	sf::Sound s;
public:
	Entity();
	int hitpoints;
	virtual void draw(sf::RenderWindow & window) = 0;
	virtual ~Entity();
	virtual void update(TileMap & map, Create_objects & o, Audio & audio) = 0;
	int return_life();
	virtual const type_info & return_type() = 0;
	virtual void HitByProjectile(bool & a, int & b);
	virtual void HittingSomethingP(bool & a, int & b, bool x1); //Metoda dla Projectile
	bool check_collision(const Entity * e) const;
	void return_location(float & x_arg, float & y_arg);
	virtual void SetPosition(int x, int y);

};
