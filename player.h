#pragma once

#include "character.h"

class Player : public Character
{
public:
	Player(int x, int y);
	int GetHealthRegen();
	void Regen();
protected:
	int max_health_points_;
	int health_regen_;
	int experience_;
};
