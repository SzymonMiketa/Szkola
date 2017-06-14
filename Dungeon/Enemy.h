#pragma once

#include <vector>
#include "Entity.h"

using namespace std;

class Enemy : public Entity
{
protected:
	float CurrentFrame;
	vector<sf::IntRect> frames;
	int damage;
	vector<sf::Texture> Entity_Texture;
	sf::Sprite Entity_Sprite;
public:
	int exp_given;
	void Enemy::draw(sf::RenderWindow & window);
	Enemy(sf::Texture const& texture_arg, sf::Texture const & texture2_arg);
	void update_sprite();
	const type_info & return_type();
	void HitByProjectile(bool & a, int & b);
	void HittingSomethingP(bool & a, int & b, bool x1);
	~Enemy();
};

