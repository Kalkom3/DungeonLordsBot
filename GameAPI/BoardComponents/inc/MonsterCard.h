#pragma once

#include "Action.h"

class MonsterCard
{
public:
	MonsterCard(std::string monsterName);

	const Action& GetAction() const;
private:
	Action m_MonsterAction;
};