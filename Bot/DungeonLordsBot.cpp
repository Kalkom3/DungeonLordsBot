
#include <iostream>
#include "DlLogger.h"
#include "HeroesTeam.h"
#include "BattleRound.h"
#include "TrapCard.h"

int main()
{
	HeroesTeam testTeam;

	LoggingConfig::s_printToConsole = true;
	LoggingConfig::s_logLevel = logLevel::INFO;

	testTeam.AddHero(Hero(2, 1, HeroClass::WARRIOR));
	testTeam.AddHero(Hero(3, 1, HeroClass::PRIEST));
	testTeam.AddHero(Hero(1, 1, HeroClass::WARRIOR));

	TrapCard trapCard("Poisoned dart");

	BattleRound testRound(testTeam);
	testRound.AddTrap(trapCard, 1);
	testRound.StartBattle();
	LOG(INFO) << testTeam.GetHero(1).GetHitPoints() << "-" << testTeam.GetHero(1).GetPosioned();

	return 0;
}
