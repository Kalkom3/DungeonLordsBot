#include "BattleRound.h"
#include <variant>

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
	
	m_monsters.push_back(newMonster);
}

void BattleRound::AddTrap(const TrapCard& newTrapCard, int targetPosition)
{
	Trap newTrap = Trap(newTrapCard);

	newTrap.AddTarget(targetPosition);

	m_traps.push_back(newTrap);
}

void BattleRound::StartBattle()
{
	bool monsterPlayed = false;
	//Trap phase
	for (Trap& trap : m_traps)
	{
		m_heroes.SetTrapsProtection(m_heroes.GetTeamAbilityLevel(HeroClass::THIEF));
		trap.Activate(m_heroes);
	}
	m_heroes.SetTrapsProtection(0);
	m_heroes.ResolveTeamTags();

	//Fast spell phase
	if (m_heroes.GetTeamCanCast() && m_spell.get()->IsFast() && m_heroes.GetTeamAbilityLevel(HeroClass::MAGE))
	{
		ResolveSpell();
	}

	//Monsters phase
	for (Monster& monster : m_monsters)
	{
		monsterPlayed = true;
		monster.Activate(m_heroes);
	}
	m_heroes.ResolveTeamTags();

	//Slow spell phase
	if (m_heroes.GetTeamCanCast() && !m_spell.get()->IsFast() && m_heroes.GetTeamAbilityLevel(HeroClass::MAGE))
	{
		ResolveSpell();
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
	for (auto& hero : m_heroes.GetHeroes())
	{
		hero.ResolvePosion();
	}
	return m_heroes.GetTeamSize()>0;
}

void BattleRound::ResolveSpell()
{
	switch (m_spell.get()->GetSpellType())
	{
	case SpellType::BUFF:
		m_spell->CastSpell(m_heroes);
		break;
	case SpellType::OFFENCE:
		for (auto& monster : m_monsters)
		{
			m_spell->CastSpell(monster);
		}
		break;
	case SpellType::RESOURCE:
		break;
	default:
		break;
	}
}
