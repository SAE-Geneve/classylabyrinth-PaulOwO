#include <iostream>
#include "tile.h"
#include "command.h"
#include "player.h"
#include "ennemy.h"
#include "world.h"
#include "character.h"

Command cmd;
int main()
{
	std::cout << "Welcome in the Maze!\n\n";
	cmd.ShowHelp();
	while (true)
	{
		cmd.ShowState();
		cmd.ExecuteCommand();
	}
}

/*(void win/loose
int enemy_left = 6;
while (true)
{
	if (get_player().health_points <= 0)
	{
		std::cout << "\nYou died!\n"
			<< "Better luck next time\n"
			<< "Game Over";
		return 0;
	}
	for (int x = 0; x < 23; ++x) {
		for (int y = 0; y < 8; ++y) {
			if (get_tile_at_position(x, y) == TileType::ENEMY) {

				if (get_enemy(x, y).health_points <= 0)
				{
					erase_enemy(get_enemy(x, y));
					enemy_left--;
					if (enemy_left == 0)
					{
						std::cout
							<< "Ouah you did it!\n"
							<< "You killed all the Gob\n"
							<< "You Win";
						return 0;
					}
				}
			}
		}
	}*/