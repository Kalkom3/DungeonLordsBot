
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
	
	testTeam.AddHero(Hero(5, 1, HeroClass::WARRIOR));
	testTeam.AddHero(Hero(3, 2, HeroClass::THIEF));
	testTeam.AddHero(Hero(4, 2, HeroClass::PRIEST));

	MonsterCard testMonster(MonstersList::SLIME);
	TrapCard testTrap(TrapsList::FALLING_BLADE);
	BattleRound testRound(testTeam);

	testRound.AddTrap(testTrap);
	testRound.AddMonster(testMonster);

	testRound.StartBattle();

	return 0;
}
