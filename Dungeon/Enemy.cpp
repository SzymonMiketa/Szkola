#include "Enemy.h"

#include "Create_objects.h"

Enemy::Enemy(sf::Texture const& texture_arg, sf::Texture const & texture2_arg)
{
	Entity_Texture.push_back(texture_arg);
	Entity_Texture.push_back(texture2_arg);
}

void Enemy::update_sprite()
{
	CurrentFrame += 0.05;
	if (CurrentFrame < 1)
	{
		Entity_Sprite.setTexture(Entity_Texture[0]);
	}
	else
	{
		Entity_Sprite.setTexture(Entity_Texture[1]);
	}
	if (CurrentFrame >= 2)
	{
		CurrentFrame = 0;
	}

}

const type_info & Enemy::return_type()
{
	return typeid(this);
}

void Enemy::HitByProjectile(bool & a, int & b)
{
	if (a == false)
	{
		hitpoints -= b;
	}
	
}

void Enemy::HittingSomethingP(bool & a, int & b, bool x1)
{
}





void Enemy::draw(sf::RenderWindow & window)
{
	float tmp = hitpoints; //Ile procent zycia ma przeciwnik
	tmp = tmp / maxhitpoints;
	sf::RectangleShape black_bar (sf::Vector2f(30, 2));
	sf::RectangleShape red_bar(sf::Vector2f(30 * tmp, 2));
	black_bar.setFillColor(sf::Color(0, 0, 0, 255)); //Pierwsyz pasek czarny
	red_bar.setFillColor(sf::Color(255, 0, 0, 255));
	black_bar.setPosition(x - 15, y - 15);
	red_bar.setPosition(x - 15, y - 15);
	window.draw(Entity_Sprite);
	window.draw(black_bar);
	window.draw(red_bar);
}




Enemy::~Enemy()
{
}
