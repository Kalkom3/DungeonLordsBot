#include "TrapCard.h"

TrapCard::TrapCard(std::string trapName) :
	m_TrapAction(trapName)
{

}

const Action& TrapCard::GetAction() const
{
	return m_TrapAction;
}
