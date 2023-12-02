#include "SpellEffect.h"

BuffSpellEffect::BuffSpellEffect(std::function<void(HeroTargets target)> effect) :
	m_effect(effect)
{
}

void BuffSpellEffect::operator()(ITarget& target) const
{
	m_effect(std::get<HeroTargets>(target.GetTargetEntities()));
}

OffensiveSpellEffect::OffensiveSpellEffect(std::function<void(MonstersTargets target)> effect) :
	m_effect(effect)
{
}

void OffensiveSpellEffect::operator()(ITarget& target) const
{
	m_effect(std::get<MonstersTargets>(target.GetTargetEntities()));
}

void ResourcesSpellEffect::operator()(ITarget& target) const
{
}
