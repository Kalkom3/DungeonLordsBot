#include "Effect.h"

std::map<std::string, Effect> EffectsMap::s_effectsMap = {
	{"Poisoned dart", Effect(1, SpecialEffects::POISON) },
	{"Anti-magic dart", Effect(1, SpecialEffects::CANCEL_ABILITY) },
	{"Rolling Stone", Effect(3, SpecialEffects::NONE) }
};