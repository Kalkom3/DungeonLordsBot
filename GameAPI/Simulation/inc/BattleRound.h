#pragma once

#include <vector>
#include "Monster.h"
#include "Trap.h"
#include "MonsterCard.h"
#include "TrapCard.h"
#include "HeroesTeam.h"

class BattleRound
{
public:
	BattleRound(HeroesTeam& heroesTeam);
	~BattleRound();
	void AddMonster(const MonsterCard& newMonsterCard, int targetPosition = -1, int secondTargetPosition = -1);
	void AddTrap(const TrapCard& newTrapCard , int targetPosition = 0);
	void StartBattle();
private:

	std::vector<Trap>m_Traps;
	std::vector<Monster>m_Monsters;
	HeroesTeam& m_heroes;

};
