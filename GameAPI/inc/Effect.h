#pragma once

#include<map>
#include<string>
#include<functional>
#include<optional>

class ITarget;
class HeroesTeam;
class Hero;

enum class TargetType
{
	NONE,
	FRONT,
	SECOND,
	LAST,
	TARGET,
	ALL
};

enum class EffectType
{
	DAMAGE,
	TARGET_DEBUFF,
	GROUP_DEBUFF,
	ON_KILL
};

enum class SpecialRules
{
	ON_KILL,
	DOUBLE,
	RETURN,
	NO_FIRST,
	NO_PRIEST,
	HAS_COST
};

struct EffectCost
{
	int gold;
	int food;
	int imp;
};

class Effect
{
public:
	Effect(EffectType type, std::function<int(ITarget& target, int targetPos)> effectFunction, std::vector<SpecialRules>rules = {}, EffectCost cost = { 0,0 });
	int operator()(ITarget& target, int targetPos) const;
	bool CheckRule(SpecialRules rule) const;
private:
	EffectType m_type;
	EffectCost m_cost;
	std::vector<SpecialRules> m_rules;
	std::function<int(ITarget& target, int targetPos)>m_effect = [](ITarget& target, int targetPos) { return 0; };

};

