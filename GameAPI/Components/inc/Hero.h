#pragma once

#include "ITarget.h"

#include <vector>
#include <string>

class HeroesTeam;
enum class TagsList;
enum class HeroClass
{
	PALLADIN,
	WARRIOR,
	PRIEST,
	THIEF,
	MAGE
};

class Hero : public ITarget
{
public:
	Hero(int hp, int skill, HeroClass heroClass);
	
	/// <summary> Deal damage to hero </summary>
	/// <param name="damageAmount"> Amount of damage </param>
	/// <returns> Is hero alive </returns>
	bool ReceiveDamage(int damageAmount);

	/// <summary> Restore hit points to hero </summary>
	/// <param name="healAmount"> Amount of healing </param>
	void ReceiveHealing(int healAmount);
	
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

	/// <summary> Hero max health getter </summary>
	/// <returns> Max amount of hero hit points </returns>
	int GetMaxHitPoints() const;

	/// <summary> Hero ability getter </summary>
	/// <returns> Level of hero ability </returns>
	int GetAbilityLevel() const;
	
	/// <summary> Get hero priority in team positioning </summary>
	/// <returns> Integer inticating priority (0 - max priority) </returns>
	int GetTeamPriority() const;

	/// <summary> Marks hero as positioned in team </summary>
	void SetPositionAssigned();

	/// <summary> Marks hero as positioned in team </summary>
	bool GetPositionAssigned() const;

	void SetPosioned(int posioned);
	int GetPosioned();
	bool ResolvePosion();

	void AddTag(TagsList newTag);
	bool ResolveTopTag();

	bool operator<(const Hero& other) const;
	bool operator==(const Hero& other) const;

	std::vector<std::reference_wrapper<Hero> > GetTargetEntities() override;
	
	std::string IdentifyHero() const;
	static std::string GetStringFromClass(HeroClass heroClass);
private:
	bool ResolveDamageProtection(int damageProtection, int& damageAmount);

	std::vector<TagsList>m_tags;
	HeroesTeam* m_team = nullptr;
	HeroClass m_class;
	int m_hitPoints = 1;
	int m_maxHitPoints = 1;
	int m_abitlityLevel = 0;
	int m_teamPriority = 0;
	bool m_isAlive = true;
	bool m_possitionAssigned = false;
	int m_posioned = 0;

};
