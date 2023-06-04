#pragma once

#include "Action.h"

class TrapCard
{
public: 
	TrapCard();

	void Activate(int targetPos) const;
private:
	Action m_TrapAction;
};