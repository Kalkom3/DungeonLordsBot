#pragma once

#include "Action.h"

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
	
	const Action& GetAction() const;
	static std::string GetStringFromTrap(TrapsList trap);
private:
	Action m_TrapAction;
};