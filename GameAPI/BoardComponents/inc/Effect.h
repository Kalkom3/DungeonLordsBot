#pragma once

#include<map>
#include<string>

enum class SpecialEffects
{
	NONE,
	NO_CONQUEST,
	NO_HEALING,
	CANCEL_ABILITY,
	POISON
};

enum class TargetType
{
	NONE,
	FRONT,
	SECOND,
	LAST,
	TARGET,
	ALL
};

/// <summary>
/// Struct containing data about effects of given card
/// </summary>
struct Effect
{
	int damage;
	TargetType targetType;
	SpecialEffects specialEffect;
};

class EffectsMap
{
public:
	static std::map<std::string, Effect> s_effectsMap;
};