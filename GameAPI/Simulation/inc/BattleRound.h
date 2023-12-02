#pragma once

#include <vector>
#include "Monster.h"
#include "Trap.h"
#include "MonsterCard.h"
#include "TrapCard.h"
#include "HeroesTeam.h"
#include "SpellCard.h"

class BattleRound
{
public:
	BattleRound(HeroesTeam& heroesTeam);
	void AddMonster(const MonsterCard& newMonsterCard, int targetPosition = 0, int actionNR = 0,int secondTargetPosition = 0);
	void AddTrap(const TrapCard& newTrapCard , int targetPosition = 0);
	void StartBattle();
	bool FinalizeRound();
	void ResolveSpell();

private:
	std::unique_ptr<SpellCard> m_spell;
	std::vector<Trap>m_traps;
	std::vector<Monster>m_monsters;
	HeroesTeam& m_heroes;

};
