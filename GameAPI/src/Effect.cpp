#include "Effect.h"

#include<assert.h>

#include "DlLogger.h"
#include "HeroesTeam.h"

EffectT::EffectT(int _damage, TargetType _targetType, std::function<bool(HeroesTeam& targets)> specialEffectT) :
	m_damage(_damage), m_targetType(_targetType)
{
	m_effect = [&](HeroesTeam& targets)->bool {
		if (m_targetType == TargetType::ALL)
		{
			specialEffectT(targets);
			for (int i = 0; i<targets.GetTeamSize(); i++)
			{
				if (targets.GetHero(i).ReceiveDamage(m_damage))
				{
					i--;
				}
			}
		}
		else
		{
			if (auto target = FindTarget(targets))
			{
				specialEffectT(targets);
				if (target.value().get().ReceiveDamage(m_damage))
				{

				}
			}
			else
			{
				return false;
			}
		}
		return true;
	};
}

void EffectT::AddTarget(int target)
{
}

std::optional<std::reference_wrapper<Hero>> EffectT::FindTarget(HeroesTeam& targetsPool, int targetNr)
{
	if (targetsPool.GetTeamSize() <= 0)
	{
		LOG(DEBUG) << "Cant find target: empty team";
		return std::nullopt;
	}
	switch (m_targetType)
	{

	case TargetType::FRONT:
		return targetsPool.GetHero(0);
		break;

	case TargetType::LAST:
		return targetsPool.GetHero(targetsPool.GetTeamSize()-1);
		break;

	case TargetType::SECOND:
		if (targetsPool.GetTeamSize() < 2)
		{
			LOG(DEBUG) << "Cant find target(SECOND): team size too small";
			return std::nullopt;
		}
		return targetsPool.GetHero(1);
		break;

	case TargetType::TARGET:
		if (m_targets.size() <= targetNr)
		{
			LOG(DEBUG) << "Cant find target(TARGET): no target provided";
			return std::nullopt;
		}

		if (targetsPool.GetTeamSize() < m_targets[targetNr])
		{
			LOG(DEBUG) << "Cant find target(TARGET " << m_targets[targetNr] << "): team size too small " ;
			return std::nullopt;
		}
		return targetsPool.GetHero(m_targets[targetNr]);
		break;

	case TargetType::ALL:
	case TargetType::NONE:
	default:
		LOG(DEBUG) << "Cant find target: wrong targeting type";
		return std::nullopt;
		break;
	}
}

Effect::Effect(EffectType type, std::function<int(ITarget& target, int targetPos)> effectFunction) :
	m_effectType(type), m_effect(effectFunction)
{
}

void Effect::ApplayEffect(ITarget& target, int targetPos)
{
	m_effect(target, targetPos);
}

void Effect::operator()(ITarget& target, int targetPos) const
{
	m_effect(target, targetPos);
}
