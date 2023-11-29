#pragma once

#include "Action.h"

enum class MonstersList
{
	GOBLIN,
	SLIME,
	GHOST,
	TROLL,
	WITCH,
	VAMPIRE,
	DEMON,
	DRAGON,
	GOLEM
};

class MonsterCard
{
public:
	MonsterCard(MonstersList monsterName);

	const Action& GetAction(int actionNr = 0) const;
	static std::string GetStringFromMonster(MonstersList monster);
private:
	std::string m_monsterName;
	std::vector<Action> m_MonsterActions;
};