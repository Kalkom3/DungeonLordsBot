#include "Monster.h"
#include "HeroesTeam.h"
#include "DlLogger.h"

Monster::Monster(const MonsterCard& baseMonster) :
	m_MonsterCard(baseMonster)
{
}

Monster::~Monster()
{
}

void Monster::SetAction(int actionNr)
{
	m_actionNr = actionNr;
}

void Monster::AddTarget(int targetPos)
{
	if (targetPos != -1)
	{
		m_targets.push_back(targetPos);
	}
}

void Monster::Activate(HeroesTeam& heroTeam)
{
	LOG(L_DEBUG) << "Team before:";
	heroTeam.CheckHeroesTeam();
	m_exhusted = m_MonsterCard.GetAction(m_actionNr).ApplyEffect(heroTeam, m_targets);
	LOG(L_DEBUG) << "Team after:";
	heroTeam.CheckHeroesTeam();
}

void Monster::SetExhusted(bool exhusted)
{
	m_exhusted = exhusted;
}

bool Monster::GetExhusted()
{
	return m_exhusted;
}

PossibleTargets Monster::GetTargetEntities()
{
	return *this;
}
