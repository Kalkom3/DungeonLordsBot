#include "Hero.h"
#include "HeroesTeam.h"
#include "DlLogger.h"

Hero::Hero(int hp, int skill, HeroClass heroClass) :
	m_hitPoints(hp), m_abitlityLevel(skill), m_class(heroClass), m_possitionAssigned(false), m_team(nullptr)
{
	m_teamPriority = heroClass >= HeroClass::WARRIOR ? static_cast<int>(heroClass) : 3;
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
	m_possitionAssigned = true;
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

void Hero::AddTag(std::string newTag)
{
	m_tags.push_back(newTag);
}

bool Hero::ResolveTopTag()
{
	if (m_tags.size() == 0)
	{
		return false;
	}
	m_tags[m_tags.size() - 1];
	m_tags.pop_back();
	return true;
	
}

bool Hero::operator<(const Hero& other) const
{
	LOG(L_DEBUG) << "Hero1(" << this->GetTeamPriority() << ", " << this->m_possitionAssigned << ") - Hero2(" << other.GetTeamPriority() << ")";
	if (this->GetTeamPriority() == other.GetTeamPriority())
	{
		if (this->GetTeamPriority() > 2)
		{
			LOG(L_DEBUG) << "Result = " << !m_possitionAssigned;
			return !m_possitionAssigned;
		}
		else
		{
			LOG(L_DEBUG) << "Result = " << m_possitionAssigned;
			return m_possitionAssigned;
		}
	}

	LOG(L_DEBUG) << "Result = " << (this->GetTeamPriority() > other.GetTeamPriority());
	return this->GetTeamPriority() > other.GetTeamPriority();

}

bool Hero::operator==(const Hero& other) const
{
	return m_hitPoints == other.m_hitPoints && m_abitlityLevel == other.m_abitlityLevel;
}

bool Hero::ReceiveDamage(int damageAmount)
{
	if (damageAmount >= m_hitPoints)
	{
		m_hitPoints = 0;
		m_team->ResolveHeroDeath(*this);
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