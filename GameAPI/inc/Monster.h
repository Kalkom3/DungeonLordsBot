#pragma once

#include <vector>

#include "MonsterCard.h"

class HeroesTeam;

class Monster
{
public:
	Monster(MonsterCard baseMonster);
	~Monster();

	void AddTarget(int targetPos);
	void Activate(HeroesTeam& heroTeam);

private:
	const MonsterCard& m_monsterCard;
	std::vector<int> m_targets;
}; 
