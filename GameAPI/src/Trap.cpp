#include "Trap.h"
#include "HeroesTeam.h"
#include "DlLogger.h"

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
	LOG(L_DEBUG) << "Team before:";
	heroTeam.CheckHeroesTeam();
	m_trapCard.GetAction().ApplyEffect(heroTeam, m_targets);
	LOG(L_DEBUG) << "Team after:";
	heroTeam.CheckHeroesTeam();
	
}
