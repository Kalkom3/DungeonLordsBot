#pragma once
#include <string>
#include <functional>#

class ITarget;
enum class TargetType;
enum class TagsList;

class EffectsFactory
{
public:
	static std::function<int(ITarget& target, int targetPos)> CreateDamageEffect(TargetType targetType, int damageAmount);
	static std::function<int(ITarget& target, int targetPos)> CreateDebuffFunction(TargetType targetType, TagsList debuffTag);
	static int FindTargetingByType(TargetType targetType, size_t teamSize, int targetPos);
};