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
	void ApplayEffect(ITarget& target, int targetPos);
	void operator()(ITarget& target, int targetPos) const;
private:
	EffectType m_effectType;
	std::function<int(ITarget& target, int targetPos)>m_effect = [](ITarget& target, int targetPos) { return 0; };

};


/// <summary>
/// Struct containing data about effects of given card
/// </summary>
class EffectT
{
public:
	EffectT(int _damage, TargetType _targetType, std::function<bool(HeroesTeam& targets)>specialEffect);
	void AddTarget(int target);
	
private:
	/// <summary>  Find target from hero group </summary>
	/// <param name="targetsPool"> Heroes team </param>
	/// <param name="targetNr"> Target possition </param>
	/// <returns> Optional reference to hero </returns>
	std::optional<std::reference_wrapper<Hero>> FindTarget(HeroesTeam& targetsPool, int targetNr = 0);
	int m_damage;
	TargetType m_targetType;
	std::function<bool(HeroesTeam& target)>m_effect = [](HeroesTeam& target)->bool { return false; };
	std::function<bool(HeroesTeam& target)>m_onDeathEffect = [](HeroesTeam& target)->bool { return false; };
	std::vector<int>m_targets;
};

