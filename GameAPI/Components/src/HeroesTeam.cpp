#include "HeroesTeam.h"

#include <DlLogger.h>
#include <algorithm>

HeroesTeam::HeroesTeam()
{

}


void HeroesTeam::AddHero(Hero&& hero)
{
	m_heroes.push_back(std::move(hero));	
	if (m_heroes.size() > 1)
	{
		std::sort(m_heroes.begin(), m_heroes.end());
	}
	for (size_t i = 0; i < m_heroes.size(); i++)
	{
		if (m_heroes[i].GetTeam() == nullptr)
		{
			m_heroes[i].AssignToTeam(this);
		}
	}
}

Hero& HeroesTeam::GetHero(int position)
{
	return m_heroes[position];
}

size_t HeroesTeam::GetTeamSize()
{
	return m_heroes.size();
}

void HeroesTeam::SetDefaultTeamPermissions()
{
	m_teamCanHeal = true;
	m_teamCanCast = true;
	m_teamCanConquer = true;
}

void HeroesTeam::SetTeamCanHeal(bool permissionState)
{
	m_teamCanHeal = permissionState;
}

void HeroesTeam::SetTeamCanCast(bool permissionState)
{
	m_teamCanCast = permissionState;
}

void HeroesTeam::SetTeamCanConquer(bool permissionState)
{
	m_teamCanConquer = permissionState;
}

void HeroesTeam::SetTrapsProtection(int protection)
{
	m_trapsProtection = protection;
}

bool HeroesTeam::GetTeamCanHeal()
{
	return m_teamCanHeal;
}

bool HeroesTeam::GetTeamCanCast()
{
	return m_teamCanCast;
}

bool HeroesTeam::GetTeamCanConquer()
{
	return m_teamCanConquer;
}

int HeroesTeam::GetTrapsProtection()
{
	return m_trapsProtection;
}

int HeroesTeam::GetTeamAbilityLevel(HeroClass abilityClass) const
{
	int result = 0;
	
	if (abilityClass != HeroClass::WARRIOR && abilityClass != HeroClass::PALLADIN)
	{
		for (const auto& hero : m_heroes)
		{
			if (hero.GetClass() == abilityClass || hero.GetClass() == HeroClass::PALLADIN)
			{
				result += hero.GetAbilityLevel();
			}
		}
	}

	return result;
}

void HeroesTeam::ResolveTeamTags()
{
	for (Hero& hero : m_heroes)
	{
		while (hero.ResolveTopTag()) {
		}
	}
}

void HeroesTeam::ResolveHeroDeath(Hero& hero)
{
	auto dyingHero = std::find(m_heroes.begin(), m_heroes.end(), hero);

	while (dyingHero->ResolveTopTag()) {
	}

	m_heroes.erase(dyingHero);
	CheckHeroesTeam();
}

void HeroesTeam::CheckHeroesTeam()
{
	LOG(L_DEBUG) << "";
	LOG(L_DEBUG) << "-----";
	LOG(L_DEBUG) << "HeroTeam status:";
	for (const auto& hero : m_heroes)
	{
		LOG(L_DEBUG) << hero.IdentifyHero();
	}
	LOG(L_DEBUG) << "-----";
	LOG(L_DEBUG) << "";
}

void HeroesTeam::HealTeam()
{
	int healingAmount = GetTeamAbilityLevel(HeroClass::PRIEST);
	for(auto& hero : m_heroes)
	{
		int heroWounds = hero.GetMaxHitPoints() - hero.GetHitPoints();
		if (healingAmount >= heroWounds)
		{
			LOG(L_DEBUG) << hero.IdentifyHero() << "Healed by " << heroWounds;
			hero.ReceiveHealing(heroWounds);
			healingAmount -= heroWounds;
		}
		else
		{
			LOG(L_DEBUG) << hero.IdentifyHero() << "Healed by " << healingAmount;
			hero.ReceiveHealing(healingAmount);
			healingAmount = 0;
		}
		if (healingAmount == 0)
		{
			break;
		}
	}
	LOG(L_DEBUG) << "After healing:";
	CheckHeroesTeam();
}

Hero& HeroesTeam::operator[](int position)
{
	return GetHero(position);
}

std::vector<std::reference_wrapper<Hero> > HeroesTeam::GetTargetEntities()
{
	std::vector<std::reference_wrapper<Hero> >resultVector;
	for (Hero& hero : m_heroes)
	{
		resultVector.push_back(hero);
	}
	return resultVector;
}

