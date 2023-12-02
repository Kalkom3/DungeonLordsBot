#pragma once

#include <functional>
#include "HeroesTeam.h"
#include "Monster.h"

class SpellEffect
{
public:
	SpellEffect() {};
	SpellEffect(SpellEffect&& other) noexcept = default;
	virtual ~SpellEffect() {};

	virtual void ApplyEffect() = 0;
	virtual void operator()(ITarget& target) const = 0;
};

class BuffSpellEffect : public SpellEffect
{
public:
	BuffSpellEffect(std::function<void(HeroTargets target)>effect);

	// Inherited via SpellEffect
	void operator()(ITarget& target) const override;
	void ApplyEffect() override;
private:
	std::function<void(HeroTargets target)>m_effect;

};

class OffensiveSpellEffect : public SpellEffect
{
public:
	OffensiveSpellEffect(std::function<void(MonstersTargets target)>effect);

	// Inherited via SpellEffect
	void operator()(ITarget& target) const override;
	void ApplyEffect() override;
private:
	std::function<void(MonstersTargets target)>m_effect;

};

class ResourcesSpellEffect : public SpellEffect
{
public:
	ResourcesSpellEffect(std::function<void()>effect);

	// Inherited via SpellEffect
	void operator()(ITarget& target) const override; 
	void ApplyEffect() override;
private:
	std::function<void()>m_effect;

};