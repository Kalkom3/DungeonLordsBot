#include "BattleRound.h"


BattleRound::BattleRound(HeroesTeam& heroesTeam) :
	m_heroes(heroesTeam)
{
}

BattleRound::~BattleRound()
{
}

void BattleRound::AddMonster(const MonsterCard& newMonsterCard, int targetPosition, int secondTargetPosition)
{
	Monster newMonster = Monster(newMonsterCard);

	newMonster.AddTarget(targetPosition);
	newMonster.AddTarget(secondTargetPosition);
	
	m_Monsters.push_back(newMonster);
}

void BattleRound::AddTrap(const TrapCard& newTrapCard, int targetPosition)
{
	Trap newTrap = Trap(newTrapCard);

	newTrap.AddTarget(targetPosition);

	m_Traps.push_back(newTrap);
}

void BattleRound::StartBattle()
{
	//Trap phase
	for (Trap& trap : m_Traps)
	{
		trap.Activate(m_heroes);
	}
	m_heroes.ResolveTeamTags();
	//Fast spell phase

	//Monsters phase
	for (Monster& monster : m_Monsters)
	{
		monster.Activate(m_heroes);
	}
	//Slow spell phase
	//Healing phase
	//Conques phase

}
