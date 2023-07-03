#pragma once
#include "IHero.h"
#include <vector>
#include <string>

enum class HeroClass
{
	PALLADIN,
	WARRIOR,
	PRIEST,
	THIEF,
	MAGE
};


class Hero
{
public:
	Hero(int hp, int skill, HeroClass heroClass);
	
	/// <summary> Deal damage to hero </summary>
	/// <param name="damageAmount"> Amount of damage </param>
	/// <returns> Is hero alive </returns>
	bool ReceiveDamage(int damageAmount);
	
	/// <summary> Hero class getter </summary>
	/// <returns> Enum value of hero class </returns>
	HeroClass GetClass() const;
	
	/// <summary> Get team to which hero is assigned to </summary>
	/// <returns></returns>
	HeroesTeam* GetTeam() const;

	/// <summary> Assign hero to team </summary>
	/// <param name="teamToAssign"> Pointer to team </param>
	void AssignToTeam(HeroesTeam* teamToAssign);

	/// <summary> Hero health getter </summary>
	/// <returns> Amount of hero hit points </returns>
	int GetHitPoints() const;
	
	/// <summary> Get hero priority in team positioning </summary>
	/// <returns> Integer inticating priority (0 - max priority) </returns>
	int GetTeamPriority() const;

	/// <summary> Marks hero as positioned in team </summary>
	void SetPositionAssigned();

	/// <summary> Marks hero as positioned in team </summary>
	bool GetPositionAssigned() const;

	void AddTag(std::string newTag);
	bool ResolveTopTag();

	bool operator<(const Hero& other) const;
	bool operator==(const Hero& other) const;

private:
	std::vector<std::string>m_tags;
	HeroesTeam* m_team;
	HeroClass m_class;
	int m_hitPoints;
	int m_abitlityLevel;
	int m_teamPriority;
	bool m_isAlive = true;
	bool m_possitionAssigned;

};
