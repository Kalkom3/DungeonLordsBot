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
	LOG(DEBUG) << "Team before:";
	for (int i = 0; i < heroTeam.GetTeamSize(); i++)
	{
		LOG(DEBUG) << static_cast<int>(heroTeam.GetHero(i).GetClass()) << "-" << heroTeam.GetHero(i).GetHitPoints();
	}
	m_trapCard.GetAction().ApplyEffect(heroTeam);
	LOG(DEBUG) << "Team after:";
	for (int i = 0; i < heroTeam.GetTeamSize(); i++)
	{
		LOG(DEBUG) << static_cast<int>(heroTeam.GetHero(i).GetClass()) << "-" << heroTeam.GetHero(i).GetHitPoints();
	}
	
}
