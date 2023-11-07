#pragma once

#include <vector>
#include "Effect.h"

class Hero;


/// <summary>
/// Class representing using card on board
/// </summary>
class Action
{
public:
	Action(std::string name);
	void ApplyEffect(Hero& hero) const;
	bool GetRequireTargets() const;
private:
	void ResolveSpecialEffect(Hero& hero) const;
	std::vector<Effect> GetActionEffectsFromName(std::string name);

	bool m_requireTargets = false;
	std::vector<Effect> m_actionEffects;
};