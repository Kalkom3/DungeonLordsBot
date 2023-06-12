#include "Hero.h"
#include "HeroesTeam.h"

Hero::Hero(int hp, int skill, HeroClass heroClass) :
	m_hitPoints(hp), m_abitlityLevel(skill), m_class(heroClass), m_possitionAssigned(false)
{
	m_teamPriority = heroClass > HeroClass::WARRIOR ? static_cast<int>(heroClass) : 3;
}

HeroClass Hero::GetClass() const
{
	return m_class;
}

HeroesTeam* Hero::GetTeam() const
{
	return m_team;
}

void Hero::AssignToTeam(HeroesTeam* teamToAssign)
{
	m_team = teamToAssign;
}

int Hero::GetHitPoints() const
{
	return m_hitPoints;
}

int Hero::GetTeamPriority() const
{
	return m_teamPriority;
}

bool Hero::operator<(const IHero& other)
{
	if (this->GetTeamPriority() == other.GetTeamPriority())
	{
		if (this->GetTeamPriority() > 2)
		{
			return !m_possitionAssigned;
		}
		else
		{
			return m_possitionAssigned;
		}
	}

	return this->GetTeamPriority() > other.GetTeamPriority();

}

bool Hero::GetPosioned() const
{
	return false;
}

void Hero::SetPosioned(bool posionedState)
{
}

bool Hero::ReceiveDamage(int damageAmount)
{
	if (damageAmount >= m_hitPoints)
	{
		m_hitPoints = 0;
		m_isAlive = false;
	}
	else
	{
		m_hitPoints -= damageAmount;
	}
	return m_isAlive;
}

void Hero::SetPositionAssigned()
{
	m_possitionAssigned = true;
}