#pragma once

enum class HeroClass;
class Hero;

class IHero
{
public:
	IHero() {};

	virtual bool ReceiveDamage(int damageAmount) = 0;
	virtual HeroClass GetClass() const = 0;
	virtual int GetHitPoints() const = 0;
	virtual int GetTeamPriority() const = 0;
	virtual void SetPositionAssigned() = 0;
	virtual bool operator<(const IHero&) = 0;
};
