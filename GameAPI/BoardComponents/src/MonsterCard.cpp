// DungeonLordsBot.cpp : Defines the entry point for the application.
//

#include "MonsterCard.h"

MonsterCard::MonsterCard(std::string monsterName) :
	m_MonsterAction(monsterName)
{
}

const Action& MonsterCard::GetAction() const
{
	return m_MonsterAction;
}
