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
	
	/// <summary> Deal damage to hero </summary>
	/// <param name="damageAmount"> Amount of damage </param>
	/// <returns> Is hero alive </returns>
	bool ReceiveDamage(int damageAmount) override;
	
	/// <summary> Hero class getter </summary>
	/// <returns> Enum value of hero class </returns>
	HeroClass GetClass() const override;
	
	/// <summary> Get team to which hero is assigned to </summary>
	/// <returns></returns>
	HeroesTeam* GetTeam() const override;

	/// <summary> Assign hero to team </summary>
	/// <param name="teamToAssign"> Pointer to team </param>
	void AssignToTeam(HeroesTeam* teamToAssign) override;

	/// <summary> Hero health getter </summary>
	/// <returns> Amount of hero hit points </returns>
	int GetHitPoints() const override;
	
	/// <summary> Get hero priority in team positioning </summary>
	/// <returns> Integer inticating priority (0 - max priority) </returns>
	int GetTeamPriority() const override;
	
	/// <summary> Return if hero is posioned </summary>
	/// <returns> State of poison</returns>
	bool GetPosioned() const override;

	/// <summary> Posioned setter </summary>
	/// <param name="posionedState"> Hero posioned state </param>
	void SetPosioned(bool posionedState) override;

	/// <summary> Marks hero as positioned in team </summary>
	void SetPositionAssigned() override;

	bool operator<(const IHero& other);

private:
	HeroesTeam* m_team;
	HeroClass m_class;
	int m_hitPoints;
	int m_abitlityLevel;
	int m_teamPriority;
	bool m_isAlive = true;
	bool m_posioned = false;
	bool m_possitionAssigned;

};