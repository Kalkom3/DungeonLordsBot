#include "gtest\gtest.h"
#include "BattleRound.h"

TEST(CardsTests, GoblinTest)
{
	HeroesTeam testTeam;
	testTeam.AddHero(Hero(3, 1, HeroClass::WARRIOR));
	testTeam.AddHero(Hero(4, 1, HeroClass::WARRIOR));

	MonsterCard testMonster(MonstersList::GOBLIN);
	BattleRound testRound(testTeam);

	testRound.AddMonster(testMonster);

	//round without on kill effect
	testRound.StartBattle();

	EXPECT_EQ(testTeam.GetHero(0).GetHitPoints(), 2);
	EXPECT_EQ(testTeam.GetHero(1).GetHitPoints(), 3);

	//second round with on kill effect
	testRound.StartBattle();

	EXPECT_EQ(testTeam.GetTeamSize(), 1);
	EXPECT_EQ(testTeam.GetHero(0).GetHitPoints(), 2);
}

TEST(CardsTests, WitchTest)
{
	HeroesTeam testTeam;
	testTeam.AddHero(Hero(3, 1, HeroClass::WARRIOR));
	testTeam.AddHero(Hero(5, 1, HeroClass::WARRIOR));

	MonsterCard testMonster(MonstersList::WITCH);
	BattleRound testRound(testTeam);
	BattleRound testRound2(testTeam);

	testRound.AddMonster(testMonster, 0, 1, 1);
	testRound2.AddMonster(testMonster);

	testRound.StartBattle();

	EXPECT_EQ(testTeam.GetHero(0).GetHitPoints(), 4);
	EXPECT_EQ(testTeam.GetHero(1).GetHitPoints(), 2);

	//second round with on kill effect
	testRound2.StartBattle();

	EXPECT_EQ(testTeam.GetTeamSize(), 1);
	EXPECT_EQ(testTeam.GetHero(0).GetHitPoints(), 2);
}

TEST(CardsTests, StunTests)
{
	HeroesTeam testTeam;
	testTeam.AddHero(Hero(3, 1, HeroClass::WARRIOR));
	testTeam.AddHero(Hero(5, 1, HeroClass::WARRIOR));

	MonsterCard testMonster(MonstersList::SLIME);
	BattleRound testRound(testTeam);

	testRound.AddMonster(testMonster, 0, 1);

	testRound.StartBattle();

	EXPECT_FALSE(testTeam.GetTeamCanConquer());
}

TEST(CardsTests, SplashTests)
{
	HeroesTeam testTeam;
	testTeam.AddHero(Hero(3, 1, HeroClass::WARRIOR));
	testTeam.AddHero(Hero(1, 1, HeroClass::WARRIOR));
	testTeam.AddHero(Hero(3, 1, HeroClass::WARRIOR));

	TrapCard testTrap(TrapsList::FIRE_WALL);
	BattleRound testRound(testTeam);

	testRound.AddTrap(testTrap);

	testRound.StartBattle();

	EXPECT_EQ(testTeam.GetTeamSize(), 2);
	EXPECT_EQ(testTeam.GetHero(0).GetHitPoints(), 2);
	EXPECT_EQ(testTeam.GetHero(1).GetHitPoints(), 1);
}