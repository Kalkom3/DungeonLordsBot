#include "Battle.h"

Battle::Battle(HeroesTeam&& enemies) :
	m_enemies{ std::make_unique<HeroesTeam>(std::move(enemies)) },
	m_rounds{{BattleRound(*m_enemies), BattleRound(*m_enemies), BattleRound(*m_enemies), BattleRound(*m_enemies)}},
	m_roundCounter{0}
{

}
