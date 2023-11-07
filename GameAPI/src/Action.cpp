#include "Action.h"
#include "Hero.h"
#include "HeroesTeam.h"

Action::Action(std::string name) :
	m_actionEffects(GetActionEffectsFromName(name))
{
	for (const Effect& effect : m_actionEffects)
	{
		if (effect.targetType == TargetType::TARGET)
		{
			m_requireTargets = true;
		}
	}
}

void Action::ApplyEffect(Hero& hero) const
{
	for (const Effect& effect : m_actionEffects)
	{
		hero.ReceiveDamage(effect.damage);
		ResolveSpecialEffect(hero);
	}
}

bool Action::GetRequireTargets() const
{
	return m_requireTargets;
}

void Action::ResolveSpecialEffect(Hero& hero) const
{
	switch (m_actionEffects[0].specialEffect)
	{
	case SpecialEffects::CANCEL_ABILITY:
		if (hero.GetClass() == HeroClass::MAGE)
		{
			hero.GetTeam()->SetTeamCanCast(false);
		}
		else if (hero.GetClass() == HeroClass::PRIEST)
		{
			hero.GetTeam()->SetTeamCanHeal(false);
		}
		break;

	case SpecialEffects::NO_CONQUEST:
		hero.GetTeam()->SetTeamCanConquer(false);
		break;

	case SpecialEffects::NO_HEALING:
		hero.GetTeam()->SetTeamCanHeal(false);
		break;

	case SpecialEffects::POISON:
			hero.SetPosioned(true);
		break;

	case SpecialEffects::NONE:
	default:
		break;
	}
}

std::vector<Effect> Action::GetActionEffectsFromName(std::string name)
{
	std::vector<Effect>actionEffects;

	actionEffects.push_back(EffectsMap::s_effectsMap.at(name));
	
	if (EffectsMap::s_effectsMap.contains(name + "2"))
	{
		actionEffects.push_back(EffectsMap::s_effectsMap.at(name + "2"));
	}

	return actionEffects;
}
