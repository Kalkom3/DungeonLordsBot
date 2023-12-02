#pragma once

#include <vector>

#include "MonsterCard.h"
#include "ITarget.h"

class HeroesTeam;

class Monster : public ITarget
{
public:
	Monster(const MonsterCard& baseMonster);
	~Monster();

	void SetAction(int actionNr);
	void AddTarget(int targetPos);
	void Activate(HeroesTeam& heroTeam);
	void SetExhusted(bool exhusted);
	bool GetExhusted();

	// Inherited via ITarget
	PossibleTargets GetTargetEntities() override;
private:
	const MonsterCard& m_MonsterCard;
	std::vector<int> m_targets;
	int m_actionNr = 0;
	bool m_exhusted = false;

};
