#pragma once

#include <vector>
#include "Effect.h"

class Hero;

class Action
{
public:
	Action();
	void ApplyEffect(Hero& hero) const;
private:
	void ResolveSpecialEffect(Hero& hero) const;

	std::vector<int>m_targetPositions;
	Effect m_actionEffect;
};