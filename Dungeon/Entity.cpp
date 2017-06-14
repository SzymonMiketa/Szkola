#include "Entity.h"

Entity::Entity()
{
	
}





Entity::~Entity()
{
}

int Entity::return_life()
{
	return hitpoints;
}

void Entity::HitByProjectile(bool & a, int & b)
{
}

void Entity::HittingSomethingP(bool & a, int & b, bool x1)
{
}

bool Entity::check_collision(const Entity * e) const
{
	return (((this->x - e->x) * (this->x - e->x)) + ((this->y - e->y) * (this->y - e->y)) < (this->R + e->R) * (this->R + e->R));
}

void Entity::return_location(float & x_arg, float & y_arg)
{
	x_arg = x;
	y_arg = y;
}

void Entity::SetPosition(int x, int y)
{
}



