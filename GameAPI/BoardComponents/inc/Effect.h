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

struct Effect
{
	int damage;
	SpecialEffects specialEffect;
};

class EffectsMap
{
public:
	static std::map<std::string, Effect> s_effectsMap;
};