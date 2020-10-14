#include "world.h"
#include <string>
#include "character.h"

int World::xy_world(int x, int y)
{
	if (x < 0) x = 0;
	if (x > 23) x = 23;
	if (y < 0) y = 0;
	if (y > 7) y = 7;
	return x + y * 24;
}

Enemy World::GetEnemy(int x, int y)
{
	Enemy enemy = local_enemy[{x, y}];
	enemy.SetX(x);
	enemy.SetY(y);
	return enemy;
}

Player World::GetPlayer()
{
	return local_player;
}

char World::get_tile_at_position(int x, int y)
{
	return (char)world_[xy_world( x, y)];

}

void World::SetPlayer(Player player)
{
	world_[xy_world(local_player.GetX(), local_player.GetY())] = '.';
	local_player = player;
	
	world_[xy_world(player.GetX(), player.GetY())] = 'P';
}

void World::EraseEnemy(Enemy enemy)
{

	world_[xy_world(enemy.GetX(), enemy.GetY())] = '.';
}
