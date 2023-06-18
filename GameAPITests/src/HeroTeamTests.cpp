#include "gtest\gtest.h"
#include "HeroesTeam.h"
#include "Hero.h"
#include "GameAPIMock.h"

/// <summary>
/// Test that heroes are being added to team in correct order
/// </summary>
TEST(HeroTeamTests, HeroPriorityTest) {
	HeroesTeam testTeam;
	
	testTeam.AddHero(Hero(2, 1, HeroClass::WARRIOR));
	testTeam.AddHero(Hero(3, 1, HeroClass::PRIEST));
	testTeam.AddHero(Hero(1, 1, HeroClass::WARRIOR));

	EXPECT_EQ(testTeam.GetHero(0).GetHitPoints(), 1);
	EXPECT_EQ(testTeam.GetHero(1).GetHitPoints(), 2);
	EXPECT_EQ(testTeam.GetHero(2).GetHitPoints(), 3);
}
