#include "BattleRound.h"


BattleRound::BattleRound(HeroesTeam& heroesTeam) :
	m_heroes(heroesTeam)
{
}

void BattleRound::AddMonster(const MonsterCard& newMonsterCard, int targetPosition, int actionNr, int extraTargetPosition)
{
	Monster newMonster = Monster(newMonsterCard);

	newMonster.AddTarget(targetPosition);
	newMonster.AddTarget(extraTargetPosition);
	newMonster.SetAction(actionNr);
	
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
	bool monsterPlayed = false;
	//Trap phase
	for (Trap& trap : m_Traps)
	{
		m_heroes.SetTrapsProtection(m_heroes.GetTeamAbilityLevel(HeroClass::THIEF));
		trap.Activate(m_heroes);
	}
	m_heroes.SetTrapsProtection(0);
	m_heroes.ResolveTeamTags();

	//Fast spell phase
	if (m_heroes.GetTeamCanCast() && m_heroes.GetTeamAbilityLevel(HeroClass::MAGE))
	{

	}

	//Monsters phase
	for (Monster& monster : m_Monsters)
	{
		monsterPlayed = true;
		monster.Activate(m_heroes);
	}
	m_heroes.ResolveTeamTags();

	//Slow spell phase
	if (m_heroes.GetTeamCanCast() && m_heroes.GetTeamAbilityLevel(HeroClass::MAGE))
	{

	}

	//Healing phase
	if (m_heroes.GetTeamCanHeal() && m_heroes.GetTeamAbilityLevel(HeroClass::PRIEST) > 0 && monsterPlayed)
	{
		m_heroes.HealTeam();
	}

	//Conques phase
	if (m_heroes.GetTeamCanConquer())
	{

	}
	FinalizeRound();
}

bool BattleRound::FinalizeRound()
{
	for (const auto& hero : m_heroes.GetTargetEntities())
	{
		hero.get().ResolvePosion();
	}
	return m_heroes.GetTeamSize()>0;
}
