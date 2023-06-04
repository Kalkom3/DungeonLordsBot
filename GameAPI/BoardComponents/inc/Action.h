#pragma once

#include <vector>
#include "Effect.h"

class Action
{
public:
	Action();
	void applyEffect() const;
private:
	std::vector<int>m_targetPositions;
	Effect actionEffect;
};