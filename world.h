#pragma once
#include <vector>
#include <string>
#include "ennemy.h"
#include "tile.h"
#include "player.h"
#include <map>



class World {
public: 
	char get_tile_at_position(int x, int y);
	int xy_world(int x, int y);

	

Enemy GetEnemy(int x, int y);
Player GetPlayer();
void EraseEnemy(Enemy enemy);
void SetPlayer(Player player);
private:
	
	std::string world_ =
	"########################" // 24 * 8
	"#.....E......E.....#..P#" // P is at (22, 1)
	"#######..#####..####...#"
	"#........#.............#"
	"#.E......#...E...E.....#"
	"#..##################..#"
	"#.........E............#"
	"########################";

	Player local_player{22,1};
	std::map<std::pair<int, int>, Enemy> local_enemy;

	std::vector < Enemy > enemies_;

};