#include "Effect.h"

std::map<std::string, Effect> EffectsMap::s_effectsMap = {
	//traps effects
	{"Poisoned dart", Effect(1, TargetType::TARGET, SpecialEffects::POISON) },
	{"Anti-magic dart", Effect(1, TargetType::TARGET, SpecialEffects::CANCEL_ABILITY) },
	{"Rolling Stone", Effect(3, TargetType::FRONT, SpecialEffects::NONE) },
	{"FireWall", Effect(1, TargetType::ALL, SpecialEffects::NONE) },
	{"FireWall2", Effect(1, TargetType::LAST, SpecialEffects::NONE) },
	//monsters effects
	{"Goblin", Effect(2, TargetType::FRONT, SpecialEffects::NONE) },
	{"Ghost", Effect(2, TargetType::TARGET, SpecialEffects::NONE) }
};