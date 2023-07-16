#pragma once
#include <vector>
#include <memory>

#include "ITarget.h"
#include "Hero.h"

class HeroesTeam : public ITarget 
{
public:
	HeroesTeam();

	/// <summary> Add hero to the team </summary>
	/// <param name="hero"> Hero to be added</param>
	void AddHero(Hero&& hero);

	/// <summary> Get hero on given position in team </summary>
	/// <param name="possition"> Hero position </param>
	/// <returns> Hero on given position </returns>
	Hero& GetHero(int possition);

	int GetTeamSize();

	/// <summary> Reset any combat party effects </summary>
	void SetDefaultTeamPermissions();

	/// <summary> Team permissions setters </summary>
	/// <param name="permissionState"> New permission state </param>
	void SetTeamCanHeal(bool permissionState);
	void SetTeamCanCast(bool permissionState);
	void SetTeamCanConquer(bool permissionState);

	/// <summary> Team permissions getters </summary>
	/// <returns> Concreate permission </returns>
	bool GetTeamCanHeal();
	bool GetTeamCanCast();
	bool GetTeamCanConquer();

	void ResolveHeroDeath(Hero& hero);

	Hero& operator[](int pos);


	// Inherited via ITarget
	virtual std::vector<std::reference_wrapper<Hero> > GetTargetEntities() override;
private:

	bool m_teamCanHeal = true;
	bool m_teamCanCast = true;
	bool m_teamCanConquer = true;

	std::vector<Hero>m_heroes;

};
