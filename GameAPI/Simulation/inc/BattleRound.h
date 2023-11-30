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
	void AddMonster(const MonsterCard& newMonsterCard, int targetPosition = 0, int actionNR = 0,int secondTargetPosition = 0);
	void AddTrap(const TrapCard& newTrapCard , int targetPosition = 0);
	void StartBattle();
	bool FinalizeRound();
private:

	std::vector<Trap>m_Traps;
	std::vector<Monster>m_Monsters;
	HeroesTeam& m_heroes;

};
