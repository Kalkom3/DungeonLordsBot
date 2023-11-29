#pragma once

#include "Action.h"

#include <vector>

enum class TrapsList
{
	ROLLING_BULDER,
	FALLING_BLADE,
	POSIONED_DART,
	MAGIC_DART,
	HOLE,
	POSIONED_FOOD,
	GOLDEN_RING,
	FIRE_WALL,
	IMP_KAMIKAZE
};

class TrapCard
{
public: 
	TrapCard(TrapsList trapName);
	
	const Action& GetAction(int actionNr = 0) const;
	static std::string GetStringFromTrap(TrapsList trap);
private:
	std::string m_trapName;
	std::vector<Action> m_TrapActions;
};