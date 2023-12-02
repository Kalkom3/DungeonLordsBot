#include "Hero.h"
#include "TagsMap.h"
#include "HeroesTeam.h"
#include "DlLogger.h"

Hero::Hero(int hp, int skill, HeroClass heroClass) :
	m_hitPoints(hp), m_maxHitPoints(hp), m_abitlityLevel(skill), m_class(heroClass)
{
	m_teamPriority = heroClass <= HeroClass::WARRIOR ? static_cast<int>(heroClass) : 3;
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

int Hero::GetMaxHitPoints() const
{
	return m_maxHitPoints;
}

int Hero::GetAbilityLevel() const
{
	return m_abitlityLevel;
}

int Hero::GetTeamPriority() const
{
	return m_teamPriority;
}

bool Hero::GetPositionAssigned() const
{
	return m_possitionAssigned;
}

void Hero::SetPosioned(int posionAmount)
{
	m_posioned = posionAmount;
}

int Hero::GetPosioned()
{
	return m_posioned;
}

bool Hero::ResolvePosion()
{
	if (m_posioned)
	{
		bool posionEffect = ReceiveDamage(m_posioned);
		m_posioned = 0;
		return posionEffect;
	}
	return false;
}

void Hero::AddTag(TagsList newTag)
{
	m_tags.push_back(newTag);
}

bool Hero::ResolveTopTag() 
{
	if (m_tags.size() == 0)
	{
		LOG(L_DEBUG) << "--> Hero has no more tags";
		return false;
	}
	auto resolvedTag = m_tags.at(m_tags.size() - 1);
	LOG(L_DEBUG) << "--> " << TagsMap::GetStringFromTag(resolvedTag);
	if (TagsMap::s_tagsMap.contains(resolvedTag))
	{
		TagsMap::s_tagsMap.at(resolvedTag)(*GetTeam());
	}
	else
	{
		LOG(ERROR) << "Unknown TAG detected";
	}

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
			return m_possitionAssigned;
		}
		else
		{
			LOG(L_DEBUG) << "Result = " << m_possitionAssigned;
			return !m_possitionAssigned;
		}
	}

	LOG(L_DEBUG) << "Result = " << (this->GetTeamPriority() > other.GetTeamPriority());
	return this->GetTeamPriority() < other.GetTeamPriority();

}

bool Hero::operator==(const Hero& other) const
{
	return m_hitPoints == other.m_hitPoints && m_abitlityLevel == other.m_abitlityLevel;
}

bool Hero::ReceiveDamage(int damageAmount)
{
	if (ResolveDamageProtection(m_team->GetTrapsProtection(), damageAmount))
	{
		return true;
	}

	LOG(L_DEBUG) << IdentifyHero() << " receive damage:" << damageAmount;
	if (damageAmount >= m_hitPoints)
	{
		m_hitPoints = 0;
		m_team->ResolveHeroDeath(*this);
		m_isAlive = false;
		LOG(L_DEBUG) << "!DIED!";
	}
	else
	{
		m_hitPoints -= damageAmount;
		m_isAlive = true;
		LOG(L_DEBUG) << "After damage:" << IdentifyHero();
	}
	return m_isAlive;
}

void Hero::ReceiveHealing(int healAmount)
{
	m_hitPoints += healAmount;
}

void Hero::SetPositionAssigned()
{
	m_possitionAssigned = true;
}

std::string Hero::IdentifyHero() const
{
	return Hero::GetStringFromClass(GetClass()) + "[" + std::to_string(GetAbilityLevel()) + "](HP:" + std::to_string(GetHitPoints()) + "/" + std::to_string(GetMaxHitPoints()) + ")";
}

std::string Hero::GetStringFromClass(HeroClass heroClass)
{
	switch (heroClass)
	{
	case HeroClass::PALLADIN:
		return "PALLADIN";
		break;
	case HeroClass::WARRIOR:
		return "WARRIOR";
		break;
	case HeroClass::PRIEST:
		return "PRIEST";
		break;
	case HeroClass::THIEF:
		return "THIEF";
		break;
	case HeroClass::MAGE:
		return "MAGE";
		break;
	default:
		return "";
		break;
	}
}

bool Hero::ResolveDamageProtection(int damageProtection, int& damageAmount)
{
	if (damageProtection > 0)
	{
		if (damageProtection > damageAmount)
		{
			LOG(L_DEBUG) << "Hero" << static_cast<int>(this->GetClass()) << "Protected by thievery(" << damageProtection << "->" << (damageProtection - damageAmount) << ")";
			m_team->SetTrapsProtection(damageProtection - damageAmount);
			return true;
		}
		else
		{
			LOG(L_DEBUG) << "Hero" << static_cast<int>(this->GetClass()) << "Protected by thievery(" << damageProtection << ")";
			damageAmount -= damageProtection;
			m_team->SetTrapsProtection(0);
		}
	}
	return false;
}
