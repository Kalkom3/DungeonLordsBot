#pragma once

#include <vector>

#include "MonsterCard.h"

class Monster
{
public:
	Monster(const MonsterCard& baseMonster);
	~Monster();

	void AddTarget(int targetPos);
	void Activate();

private:
	const MonsterCard& m_trapCard;
	std::vector<int> m_targets;
}; 
