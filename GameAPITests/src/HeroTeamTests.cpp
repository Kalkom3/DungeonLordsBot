#include "gtest\gtest.h"
#include "HeroesTeam.h"
#include "Hero.h"

/// <summary>
/// Test that heroes are being added to team in correct order
/// </summary>
TEST(HeroTeamTests, HeroPriorityTest) {
	HeroesTeam testTeam;
	
	testTeam.AddHero(Hero(2, 1, HeroClass::WARRIOR));
	testTeam.AddHero(Hero(3, 1, HeroClass::PRIEST));
	testTeam.AddHero(Hero(1, 1, HeroClass::WARRIOR));
	testTeam.AddHero(Hero(4, 1, HeroClass::PRIEST));

	EXPECT_EQ(testTeam.GetHero(0).GetHitPoints(), 1);
	EXPECT_EQ(testTeam.GetHero(1).GetHitPoints(), 2);
	EXPECT_EQ(testTeam.GetHero(2).GetHitPoints(), 3);
	EXPECT_EQ(testTeam.GetHero(3).GetHitPoints(), 4);
}

/// <summary>
/// Test that heroes correctly reposition after death
/// </summary>
TEST(HeroTeamTests, HeroReAsingnTest) {
	HeroesTeam testTeam;
	
	testTeam.AddHero(Hero(2, 1, HeroClass::WARRIOR));
	testTeam.AddHero(Hero(3, 1, HeroClass::PRIEST));
	testTeam.AddHero(Hero(1, 1, HeroClass::WARRIOR));

	//kill second hero
	testTeam.GetHero(1).ReceiveDamage(2);

	//check size of team and heroes positions
	EXPECT_EQ(testTeam.GetTeamSize(), 2);
	EXPECT_EQ(testTeam.GetHero(0).GetHitPoints(), 1);
	EXPECT_EQ(testTeam.GetHero(1).GetHitPoints(), 3);
}
