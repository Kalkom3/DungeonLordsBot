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


class Effect
{
public:
	Effect(EffectType type, std::function<int(ITarget& target, int targetPos)> effectFunction);
	void operator()(ITarget& target, int targetPos) const;
private:
	EffectType m_effectType;
	std::function<int(ITarget& target, int targetPos)>m_effect = [](ITarget& target, int targetPos) { return 0; };

};

