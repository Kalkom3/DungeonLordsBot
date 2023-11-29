#pragma once

#include <vector>

#include "MonsterCard.h"

class HeroesTeam;

class Monster
{
public:
	Monster(const MonsterCard& baseMonster);
	~Monster();

	void AddTarget(int targetPos);
	void Activate(HeroesTeam& heroTeam);

private:
	const MonsterCard& m_MonsterCard;
	std::vector<int> m_targets;
};
