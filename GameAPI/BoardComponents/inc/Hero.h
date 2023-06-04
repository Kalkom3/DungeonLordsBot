#pragma once
#include "IHero.h"

enum class HeroClass
{
	PALLADIN,
	WARRIOR,
	PRIEST,
	THIEF,
	MAGE
};

class Hero : public IHero
{
public:
	Hero(int hp, int skill, HeroClass heroClass);
	
	bool ReceiveDamage(int damageAmount) override;
	HeroClass GetClass() const override;
	int GetHitPoints() const override;
	int GetTeamPriority() const override;
	void SetPositionAssigned() override;

	bool operator<(const IHero& other);

private:
	HeroClass m_class;
	int m_hitPoints;
	int m_abitlityLevel;
	int m_teamPriority;
	bool m_isAlive = true;
	bool m_possitionAssigned;
};