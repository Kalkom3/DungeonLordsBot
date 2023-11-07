#pragma once

#include "Action.h"

class TrapCard
{
public: 
	TrapCard(std::string trapName);

	const Action& GetAction() const;
private:
	Action m_TrapAction;
};