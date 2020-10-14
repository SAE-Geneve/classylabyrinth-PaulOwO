#include "character.h"
#include <iostream>

Character::Character()
{

}

Character::Character(int health_points, int attack, int x, int y, int defence, std::string name) :
	health_points_(health_points),
	attack_(attack),
	x_(x),
	y_(y),
	defence_(defence),
	name_(name)
{}

int Character::GetX()
{
	return x_;
}

int Character::GetY()
{
	return y_;
}

void Character::SetX(int x)
{
	x_ = x;
}

void Character::SetY(int y)
{
	y_ = y;
}

int Character::GetAttack()
{
	return attack_;
}

int Character::GetDefence()
{
	return defence_;
}

int Character::GetHealthPoints()
{
	return 	health_points_;
}

void Character::SetHealthPoints(int health)
{
	health_points_ = health;
}

void Character::PrintName()
{
	std::cout << name_;
}
