#include "player.h"

Player::Player(int x, int y) :
	Character(100, 60, 22, 1, 3, "The Hero"),
	health_regen_(5),
	max_health_points_(100),
	experience_(0) {}

int Player::GetHealthRegen()
{
	return health_regen_;
}

void Player::Regen()
{
	health_points_ += health_regen_;
	health_points_ = std::min(health_points_, max_health_points_);

}