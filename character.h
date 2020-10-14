#pragma once
#include <string>



class Character
{
public:
	Character();
	Character(int health_points, int attack, int x, int y, int defence, std::string name);
	int GetX();
	int GetY();
	int GetHealthPoints();
	int GetAttack();
	int GetDefence();
	void SetX(int x);
	void SetY(int y);
	void SetHealthPoints(int health);
	void PrintName();
protected:
	int x_;
	int y_;
	int health_points_;
	int attack_;
	int defence_;
	std::string name_;
};

