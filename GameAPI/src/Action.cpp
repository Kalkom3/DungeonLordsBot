#include "Action.h"
#include "Hero.h"
#include "HeroesTeam.h"
#include "EffectsMap.h"

Action::Action(std::string name) :
	m_actionEffects(GetActionEffectsFromName(name)), m_targetPosition(0)
{

}

void Action::ApplyEffect(HeroesTeam& heroes) const
{
	for (const Effect& effect : m_actionEffects)
	{
		effect(heroes, m_targetPosition);
	}
}

bool Action::GetRequireTargets() const
{
	return m_requireTargets;
}

void Action::ResolveSpecialEffect(Hero& hero) const
{

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
