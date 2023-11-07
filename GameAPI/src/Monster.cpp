#include "Monster.h"

#include "HeroesTeam.h"

Monster::Monster(MonsterCard baseMonster) :
	m_monsterCard(baseMonster)
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
	for (int i = 0; i < m_targets.size(); i++)
	{
		m_monsterCard.GetAction().ApplyEffect(heroTeam.GetHero(m_targets.at(i)));
	}
}
