#pragma once

#include "Effect.h"

class EffectsMap
{
	using ddd = std::function<void(ITarget& target, int targetPos)>;
public:
	static std::map<std::string, Effect> s_effectsMap;
};