#pragma once
#include "BattleRound.h"
#include <array>
class Battle
{
public:
	Battle(HeroesTeam&& enemies);

private:
	std::unique_ptr<HeroesTeam>m_enemies;
	std::array<BattleRound, 4>m_rounds;
	int m_roundCounter = 0;
};

