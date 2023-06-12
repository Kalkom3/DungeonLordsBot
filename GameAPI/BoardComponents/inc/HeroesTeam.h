#pragma once
#include <vector>
#include <memory>

class IHero;

class HeroesTeam
{
public:
	HeroesTeam();

	/// <summary> Add hero to the team </summary>
	/// <param name="hero"> Hero to be added</param>
	void AddHero(std::unique_ptr<IHero>&& hero);

	/// <summary> Get hero on given position in team </summary>
	/// <param name="possition"> Hero position </param>
	/// <returns> Hero on given position </returns>
	const IHero& GetHero(int possition) const;

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

private:
	bool m_teamCanHeal = true;
	bool m_teamCanCast = true;
	bool m_teamCanConquer = true;

	std::vector<std::unique_ptr<IHero> >m_heroes;
};
