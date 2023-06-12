#include "HeroesTeam.h"
#include "Hero.h"

#include <algorithm>

HeroesTeam::HeroesTeam()
{

}

void HeroesTeam::AddHero(std::unique_ptr<IHero>&& hero)
{
	m_heroes.push_back(std::move(hero));
	IHero& newHero = *m_heroes[m_heroes.size() - 1];	

	std::sort(m_heroes.begin(),m_heroes.end());
	
	newHero.AssignToTeam(this);
	newHero.SetPositionAssigned();
}

const IHero& HeroesTeam::GetHero(int possition) const
{
	return *m_heroes.at(possition);
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
