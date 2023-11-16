#include "Action.h"
#include "Hero.h"
#include "HeroesTeam.h"
#include "EffectsMap.h"

Action::Action(std::string name) :
	m_actionEffects(GetActionEffectsFromName(name)), m_targetPosition(0)
{

}

void Action::ApplyEffect(HeroesTeam& heroes, std::vector<int> targets) const
{
	int targetIterator = 0;
	for (const Effect& effect : m_actionEffects)
	{
		if (targets.size() > 0)
		{
			effect(heroes, targets[targetIterator]);
			if (targets.size() == 2)
			{
				targetIterator = 1;
			}
		}
		else
		{
			effect(heroes, 0);
		}

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
	if (EffectsMap::s_effectsMap.contains(name))
	{
		actionEffects.push_back(EffectsMap::s_effectsMap.at(name));

		if (EffectsMap::s_effectsMap.contains(name + "2"))
		{
			actionEffects.push_back(EffectsMap::s_effectsMap.at(name + "2"));
		}
	}

	return actionEffects;
}
