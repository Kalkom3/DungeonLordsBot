#include "MonsterCard.h"
#include "EffectsMap.h"

MonsterCard::MonsterCard(MonstersList monsterName) :
	m_monsterName(GetStringFromMonster(monsterName))
{
	int effectNr = 1;
	std::string nameToSearch = m_monsterName;
	while (EffectsMap::s_effectsMap.contains(nameToSearch))
	{
		m_MonsterActions.push_back(Action(nameToSearch));
		effectNr++;
		nameToSearch = m_monsterName + "_" + std::to_string(effectNr);
	}
}

const Action& MonsterCard::GetAction(int actionNr) const
{
	return m_MonsterActions[actionNr];
}


std::string MonsterCard::GetStringFromMonster(MonstersList monster)
{
	switch (monster)
	{
	case MonstersList::GOBLIN:
			return "Goblin";
		break;
	case MonstersList::SLIME:
			return "Slime";
		break;
	case MonstersList::GHOST:
			return "Ghost";
		break;
	case MonstersList::TROLL:
			return "Troll";
		break;
	case MonstersList::WITCH:
			return "Witch";
		break;
	case MonstersList::VAMPIRE:
			return "Vampire";
		break;
	case MonstersList::DEMON:
			return "Demon";
		break;
	case MonstersList::DRAGON:
			return "Dragon";
		break;
	case MonstersList::GOLEM:
			return "Golem";
		break;
	default:
		break;
	}
}