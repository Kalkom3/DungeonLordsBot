#include "HeroesTeam.h"

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
	for (int i = 0; i < m_heroes.size(); i++)
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

int HeroesTeam::GetTeamSize()
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

void HeroesTeam::ResolveHeroDeath(Hero& hero)
{
	int heroPos = -1;// = std::find(m_heroes.begin(), m_heroes.end(), hero);
	for (int i = 0; i < m_heroes.size(); i++)
	{
		if (m_heroes[i] == hero)
		{
			heroPos = i;
		}
	}
	while(m_heroes[heroPos].ResolveTopTag()) {}
	m_heroes.erase(m_heroes.begin() + heroPos);
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
