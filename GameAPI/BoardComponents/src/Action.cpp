#include "Action.h"
#include "Hero.h"

Action::Action()
{

}

void Action::ApplyEffect(Hero& hero) const
{
	hero.ReceiveDamage(m_actionEffect.damage);
}

void Action::ResolveSpecialEffect(Hero& hero) const
{
	switch (m_actionEffect.specialEffect)
	{
	case SpecialEffects::CANCEL_ABILITY:

		break;

	case SpecialEffects::NO_CONQUEST:

		break;

	case SpecialEffects::NO_HEALING:
			
		break;

	case SpecialEffects::POISON:
			hero.SetPosioned(true);
		break;

	case SpecialEffects::NONE:
	default:
		break;
	}
}
