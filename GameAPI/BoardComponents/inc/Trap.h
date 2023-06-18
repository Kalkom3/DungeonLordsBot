#pragma once

#include <vector>

#include "TrapCard.h"

class HeroesTeam;

class Trap
{
public:
	Trap(const TrapCard& baseTrap);
	~Trap();

	void AddTarget(int targetPos);
	void Activate(HeroesTeam& heroTeam);

private:
	const TrapCard& m_trapCard;
	std::vector<int> m_targets;
};