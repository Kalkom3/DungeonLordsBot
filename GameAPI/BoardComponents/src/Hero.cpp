#include "Hero.h"
#include "HeroesTeam.h"
#include "DlLogger.h"

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

bool Hero::GetPositionAssigned() const
{
	return m_possitionAssigned;
}

bool Hero::operator<(const Hero& other) const
{
	LOG(DEBUG) << "Hero1(" << this->GetTeamPriority() << ", " << this->m_possitionAssigned << ") - Hero2(" << other.GetTeamPriority() << ")";
	if (this->GetTeamPriority() == other.GetTeamPriority())
	{
		if (this->GetTeamPriority() > 2)
		{
			LOG(DEBUG) << "Result = " << !m_possitionAssigned;
			return !m_possitionAssigned;
		}
		else
		{
			LOG(DEBUG) << "Result = " << m_possitionAssigned;
			return m_possitionAssigned;
		}
	}

	LOG(DEBUG) << "Result = " << (this->GetTeamPriority() > other.GetTeamPriority());
	return this->GetTeamPriority() > other.GetTeamPriority();

}

bool Hero::GetPosioned() const
{
	return m_posioned;
}

void Hero::SetPosioned(bool posionedState)
{
	m_posioned = posionedState;
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