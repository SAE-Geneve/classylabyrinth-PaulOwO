#pragma once
#include "world.h"
#include "tile.h"
class Command {
public:
	void North();
	void South();
	void East();
	void West();
	//void Attack(Character, Character);
	void PlayerAttack();
	void EnemyAttack();
	void Tick();
	void ShowState();
	void ShowHelp();
	char GetCommand();
	void ExecuteCommand();
private:	
	World world_;
};

