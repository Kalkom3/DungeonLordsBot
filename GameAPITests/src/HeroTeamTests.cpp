#include "gtest\gtest.h"
#include "HeroesTeam.h"
#include "GameAPIMock.h"

/// <summary>
/// Test that heroes are being added to team in correct order
/// </summary>
TEST(HeroTeamTests, HeroPriorityTest) {
	HeroesTeam testTeam;
	
	testTeam.AddHero(std::make_unique<Hero>(2, 1, HeroClass::WARRIOR));
	testTeam.AddHero(std::make_unique<Hero>(3, 1, HeroClass::PRIEST));
	testTeam.AddHero(std::make_unique<Hero>(1, 1, HeroClass::WARRIOR));

	EXPECT_EQ(testTeam.GetHero(0).GetHitPoints(), 1);
	EXPECT_EQ(testTeam.GetHero(1).GetHitPoints(), 2);
	EXPECT_EQ(testTeam.GetHero(2).GetHitPoints(), 3);
}
