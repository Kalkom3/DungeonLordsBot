#pragma once

#include <vector>

#include "TrapCard.h"

class Trap
{
public:
	Trap(const TrapCard& baseTrap);
	~Trap();

	void AddTarget(int targetPos);
	void Activate();

private:
	const TrapCard& m_trapCard;
	std::vector<int> m_targets;
};