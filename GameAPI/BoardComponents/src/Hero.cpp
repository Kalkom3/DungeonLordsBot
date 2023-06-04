#include "Hero.h"

Hero::Hero(int hp, int skill, HeroClass heroClass) :
	m_hitPoints(hp), m_abitlityLevel(skill), m_class(heroClass), m_possitionAssigned(false)
{
	m_teamPriority = heroClass > HeroClass::WARRIOR ? static_cast<int>(heroClass) : 3;
}

HeroClass Hero::GetClass() const
{
	return m_class;
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