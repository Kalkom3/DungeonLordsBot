#include "Trap.h"
#include "HeroesTeam.h"

Trap::Trap(const TrapCard& baseTrap):
	m_trapCard(baseTrap)
{
}

Trap::~Trap()
{
}

void Trap::AddTarget(int targetPos)
{
	m_targets.push_back(targetPos);
}

void Trap::Activate(HeroesTeam& heroTeam)
{
	for (int i = 0; i < m_targets.size(); i++)
	{
		m_trapCard.GetAction().ApplyEffect(heroTeam.GetHero(m_targets.at(i)));
	}
}
