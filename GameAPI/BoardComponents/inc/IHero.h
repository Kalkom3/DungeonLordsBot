#pragma once

enum class HeroClass;
class HeroesTeam;

class IHero
{
public:
	IHero() {};

	virtual bool ReceiveDamage(int damageAmount) = 0;
	virtual HeroClass GetClass() const = 0;
	virtual HeroesTeam* GetTeam() const = 0;
	virtual void AssignToTeam(HeroesTeam* teamToAssign) = 0;
	virtual int GetHitPoints() const = 0;
	virtual int GetTeamPriority() const = 0;
	virtual bool GetPosioned() const = 0;
	virtual void SetPosioned(bool posionedState) = 0;
	virtual void SetPositionAssigned() = 0;
	virtual bool GetPositionAssigned() const = 0;
};
