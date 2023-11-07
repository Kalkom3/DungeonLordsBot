
#include <iostream>
#include "DlLogger.h"
#include "HeroesTeam.h"
#include "BattleRound.h"
#include "TrapCard.h"

int main()
{
	HeroesTeam testTeam;

	LoggingConfig::s_printToConsole = true;
	LoggingConfig::s_logLevel = logLevel::L_DEBUG;
	
	testTeam.AddHero(Hero(1, 1, HeroClass::WARRIOR));
	testTeam.AddHero(Hero(2, 1, HeroClass::PRIEST));
	testTeam.AddHero(Hero(4, 1, HeroClass::MAGE));

	TrapCard testTrap("Hole");
	
	BattleRound testRound(testTeam);

	testRound.AddTrap(testTrap, 1);

	testRound.StartBattle();

	return 0;
}
