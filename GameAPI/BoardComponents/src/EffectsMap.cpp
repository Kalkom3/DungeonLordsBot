#include "EffectsMap.h"
#include "EffectsFactory.h"

std::map<std::string, Effect> EffectsMap::s_effectsMap = {
	{
		"FireWall",
		Effect(
			EffectType::DAMAGE,
			EffectsFactory::CreateDamageEffect(TargetType::ALL, 1)
		)
	},
	{
		"FireWall2",
		Effect(
			EffectType::DAMAGE,
			EffectsFactory::CreateDamageEffect(TargetType::LAST, 1)
		)
	},
	{
		"RollingBulder",
		Effect(
			EffectType::DAMAGE,
			EffectsFactory::CreateDamageEffect(TargetType::FRONT, 3)
		)
	},
	{
		"FallingBlade",
		Effect(
			EffectType::DAMAGE,
			EffectsFactory::CreateDamageEffect(TargetType::SECOND, 3)
		)
	},
	{
		"Hole",
		Effect(
			EffectType::GROUP_DEBUFF,
			EffectsFactory::CreateDebuffFunction(TargetType::FRONT, "Stunned")
		)
	},
	{
		"Hole2",
		Effect(
			EffectType::DAMAGE,
			EffectsFactory::CreateDamageEffect(TargetType::FRONT, 2)
		)
	},
	{
		"Posioned_Dart",
		Effect(
			EffectType::TARGET_DEBUFF,
			EffectsFactory::CreateDebuffFunction(TargetType::TARGET, "Posioned")
		)
	},
	{
		"Posioned_Dart2",
		Effect(
			EffectType::DAMAGE,
			EffectsFactory::CreateDamageEffect(TargetType::TARGET, 1)
		)
	},
};

