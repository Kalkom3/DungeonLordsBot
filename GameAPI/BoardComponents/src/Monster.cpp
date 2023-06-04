#include "Monster.h"

Monster::Monster(const MonsterCard& baseMonster) :
	m_trapCard(baseMonster)
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
