#pragma once
#include <vector>
#include <memory>

#include "Hero.h"

class HeroesTeam
{
public:
	HeroesTeam();

	void AddHero(std::unique_ptr<IHero>&& hero);
	const IHero& GetHero(int possition) const;

private:
	std::vector<std::unique_ptr<IHero> >m_heroes;
};
