#include "Monster.h"

Monster::Monster(MonsterCard baseMonster) :
	m_monsterCard(baseMonster)
{
}

Monster::~Monster()
{
}

void Monster::AddTarget(int targetPos)
{
	m_targets.push_back(targetPos);
}

void Monster::Activate()
{

}
