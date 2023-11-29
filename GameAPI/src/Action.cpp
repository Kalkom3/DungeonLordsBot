#include "Action.h"
#include "Hero.h"
#include "HeroesTeam.h"
#include "EffectsMap.h"

Action::Action(std::string name) :
	m_actionEffects(GetActionEffectsFromName(name)), m_targetPosition(0)
{

}

bool Action::ApplyEffect(HeroesTeam& heroes, std::vector<int> targets) const
{
	bool exhust = true;
	int kills = 0;
	int targetIterator = 0;
	for (const Effect& effect : m_actionEffects)
	{
		if (effect.CheckRule(SpecialRules::ON_KILL) && kills == 0 || 
			effect.CheckRule(SpecialRules::HAS_COST) && false//here cost check
			)
		{
			continue;
		}

		if (effect.CheckRule(SpecialRules::RETURN))
		{
			exhust = false;
		}

		if (targets.size() > 0)
		{
			kills += effect(heroes, targets[targetIterator]);
			if (targets.size() == 2)
			{
				targetIterator = 1;
			}
		}
		else
		{
			kills += effect(heroes, 0);
		}

	}
	return exhust;
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
	std::string nameToSearch = name;
	int effectNr = 1;
	while (EffectsMap::s_effectsMap.contains(nameToSearch))
	{
		actionEffects.push_back(EffectsMap::s_effectsMap.at(name));
		effectNr++;
		nameToSearch = name + "." + std::to_string(effectNr);
	}

	return actionEffects;
}
