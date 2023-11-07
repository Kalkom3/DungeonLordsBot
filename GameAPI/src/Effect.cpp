#include "Effect.h"

#include "DlLogger.h"
#include "HeroesTeam.h"

Effect::Effect(EffectType type, std::function<int(ITarget& target, int targetPos)> effectFunction) :
	m_effectType(type), m_effect(effectFunction)
{
}

void Effect::operator()(ITarget& target, int targetPos) const
{
	m_effect(target, targetPos);
}
