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

void Monster::AddTarget(int targetPos)
{
	m_targets.push_back(targetPos);
}

void Monster::Activate(HeroesTeam& heroTeam)
{
	LOG(L_DEBUG) << "Team before:";
	heroTeam.CheckHeroesTeam();
	m_MonsterCard.GetAction().ApplyEffect(heroTeam, m_targets);
	LOG(L_DEBUG) << "Team after:";
	heroTeam.CheckHeroesTeam();

}
