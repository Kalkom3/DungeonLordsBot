#include "HeroesTeam.h"
#include <algorithm>

HeroesTeam::HeroesTeam()
{

}

void HeroesTeam::AddHero(std::unique_ptr<IHero>&& hero)
{
	m_heroes.push_back(std::move(hero));
	IHero& newHero = *m_heroes[m_heroes.size() - 1];	

	std::sort(m_heroes.begin(),m_heroes.end());

	newHero.SetPositionAssigned();
}

const IHero& HeroesTeam::GetHero(int possition) const
{
	return *m_heroes.at(possition);
}
