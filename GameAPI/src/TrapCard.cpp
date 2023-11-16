#include "TrapCard.h"

TrapCard::TrapCard(TrapsList trapName) :
	m_TrapAction(GetStringFromTrap(trapName))
{

}

const Action& TrapCard::GetAction() const
{
	return m_TrapAction;
}


std::string TrapCard::GetStringFromTrap(TrapsList trap)
{
	switch (trap)
	{
	case TrapsList::ROLLING_BULDER:
			return "Roling_Bulder";
		break;
	case TrapsList::FALLING_BLADE:
			return "Falling_Blade";
		break;
	case TrapsList::POSIONED_DART:
			return "Posioned_Dart";
		break;
	case TrapsList::MAGIC_DART:
			return "Magic_Dart";
		break;
	case TrapsList::HOLE:
			return "Hole";
		break;
	case TrapsList::POSIONED_FOOD:
			return "Posioned_Food";
		break;
	case TrapsList::GOLDEN_RING:
			return "Golden_Ring";
		break;
	case TrapsList::FIRE_WALL:
			return "Fire_Wall";
		break;
	case TrapsList::IMP_KAMIKAZE:
			return "Imp_Kamikaze";
		break;
	default:
		break;
	}
}