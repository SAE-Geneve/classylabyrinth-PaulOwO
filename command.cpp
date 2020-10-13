#include <vector>
#include "command.h"
#include "character.h"
#include "player.h"
#include <iostream>
#include "world.h"




void Command::North()
{
	Player player = world_.GetPlayer();
	
	if (world_.get_tile_at_position(player.GetX(),player.GetY() - 1) != '.')
		return;
	else
	player.SetY(player.GetY() - 1);
	world_.SetPlayer(player);
}

void Command::South()
{
	Player player = world_.GetPlayer();

	if (world_.get_tile_at_position(player.GetX(), player.GetY() + 1) != '.')
		return;
	else
	player.SetY(player.GetY() + 1);
	world_.SetPlayer(player);
}

void Command::East()
{
	Player player = world_.GetPlayer();

	if (world_.get_tile_at_position(player.GetX() + 1, player.GetY()) != '.')
		return;
	else
		player.SetX(player.GetX() + 1);
	world_.SetPlayer(player);
}

void Command::West()
{
	Player player = world_.GetPlayer();

	if (world_.get_tile_at_position(player.GetX() - 1, player.GetY()) != '.')
		return;
	else
		player.SetX(player.GetX() - 1);
	world_.SetPlayer(player);	
}

/*void Command::Attack(Character1,Character2)
{
	Character2.health_points -= std::max(0, Character1.attack - Character2.defence);
	set_player(player);
	set_enemy(enemy, enemy.x, enemy.y);
}*/


void Command::PlayerAttack()
{
	Player player = world_.GetPlayer();
	std::vector<Enemy> enemy_vec;
	if (world_.get_tile_at_position(player.GetX(), player.GetY() - 1) == 'E')
		enemy_vec.push_back(world_.GetEnemy(player.GetX(), player.GetY() - 1));
	if (world_.get_tile_at_position(player.GetX(), player.GetY() + 1) == 'E')
		enemy_vec.push_back(world_.GetEnemy(player.GetX(), player.GetY() + 1));
	if (world_.get_tile_at_position(player.GetX() - 1, player.GetY()) == 'E')
		enemy_vec.push_back(world_.GetEnemy(player.GetX() - 1, player.GetY()));
	if (world_.get_tile_at_position(player.GetX() + 1, player.GetY()) == 'E')
		enemy_vec.push_back(world_.GetEnemy(player.GetX() + 1, player.GetY()));
	for (auto& enemy : enemy_vec)
		enemy.SetHealthPoints(enemy.GetHealthPoints() - player.GetAttack() + enemy.GetDefence());
}

void Command::EnemyAttack()
{

}

void Command::Tick()
{
	Player player = world_.GetPlayer();
	player.Regen();
	//EnnemyAttack()
}


void Command::ShowState()
{
	Player player = world_.GetPlayer();
	// Show the maze to the user.
	std::cout << "Maze :\n";
	for (int i = -1; i < 2; ++i)
	{
		std::cout << "\t +---+---+---+\n\t";
		for (int j = -1; j < 2; ++j)
		{
			std::cout
				<< " | "
				<< (char)world_.get_tile_at_position(player.GetX() + j, player.GetY() + i);
		}
		std::cout << " |\n";
	}
	std::cout << "\t +---+---+---+\n\n";
	std::cout << "Player(" << player.GetX() << ", " << player.GetY() << ") :\n";
	std::cout << "\tname : ";
	player.PrintName();
	std::cout << "\n\thealth points : " << player.GetHealthPoints() << "\n";
	std::cout << "\n";
	for (int i = -1; i < 2; ++i)
	{
		for (int j = -1; j < 2; ++j)
		{
			if ('E' ==
				world_.get_tile_at_position(player.GetX() + i, player.GetY() + j))
			{
				Enemy enemy = world_.GetEnemy(player.GetX() + i, player.GetY() + j);
				std::cout
					<< "Enemy(" << player.GetX() + i	
					<< ", " << player.GetY() + j
					<< ")\n";
				std::cout << "\tname : ";  
				enemy.PrintName();
				std::cout << "\n\thealth points : " << enemy.GetHealthPoints() << "\n";
				std::cout << "\n";
			}
		}
	}
}

void Command::ShowHelp()
{
	std::cout << "Valid options:\n"
	    << "\t[q]uit  -> quit the game.\n"
	    << "\t[n]orth -> move north.\n"
		<< "\t[s]outh -> move south.\n"
		<< "\t[e]ast -> move east.\n"
		<< "\t[w]est -> move west.\n"
		<< "\t[a]ttack -> attack enemy.\n"
		<< "\t[h]elp -> show help.\n";
}

char Command::GetCommand()
{
	std::cout << "] ";
	std::string command_str;
	std::getline(std::cin, command_str);
	return command_str[0];
}

void Command::ExecuteCommand()
{
	
	switch (GetCommand())
	{
	case 'q':
		std::cout << "Ciao!\n";
		exit(0);
	case 'n':
		return North();
		break;
	case 's':
		return South();
		break;
	case 'e':
		return East();
		break;
	case 'w':
		return West();
		break;
	case 'a':
		return PlayerAttack();
		break;
	case 'h':
	default:
		ShowHelp();
		break;
	}
	Tick();
}
