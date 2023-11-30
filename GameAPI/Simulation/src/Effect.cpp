#include "Effect.h"

#include "DlLogger.h"
#include "HeroesTeam.h"

Effect::Effect(EffectType type, std::function<int(ITarget& target, int targetPos)> effectFunction, std::vector<SpecialRules>rules, EffectCost cost) :
	m_type(type), m_effect(effectFunction), m_rules(rules), m_cost(cost)
{
}

int Effect::operator()(ITarget& target, int targetPos) const
{
	return m_effect(target, targetPos);
}

bool Effect::CheckRule(SpecialRules rule) const
{
	return std::find(m_rules.begin(), m_rules.end(), rule) != m_rules.end();
}