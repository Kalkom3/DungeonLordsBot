#include "Trap.h"

Trap::Trap(const TrapCard& baseTrap):
	m_trapCard(baseTrap)
{
}

Trap::~Trap()
{
}

void Trap::AddTarget(int targetPos)
{
	m_targets.push_back(targetPos);
}

void Trap::Activate()
{
	
}
