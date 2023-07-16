#include "EffectsFactory.h"
#include "Effect.h"
#include "Hero.h"

std::function<void(ITarget& target, int targetPos)> EffectsFactory::CreateDamageEffect(TargetType targetType, int damageAmount)
{
	if (targetType == TargetType::ALL)
	{
		return [damageAmount](ITarget& targets, int targetPos) {
			for (Hero& hero : targets.GetTargetEntities())
			{
				hero.ReceiveDamage(damageAmount);
			}
		};
	}
	else
	{
		return [targetType, damageAmount](ITarget& targets, int targetPos) {
			targets.GetTargetEntities().at(
				EffectsFactory::FindTargetingByType(targetType, targets.GetTargetEntities().size(), targetPos)
			).get().ReceiveDamage(damageAmount);
		};
	}

}

std::function<void(ITarget& target, int targetPos)> EffectsFactory::CreateDebuffFunction(TargetType targetType, std::string debuffTag)
{
	if (targetType == TargetType::ALL)
	{
		return [debuffTag](ITarget& targets, int targetPos) {
			targets.GetTargetEntities().at(0).get().AddTag(debuffTag);
		};
	}
	else
	{
		return [targetType, debuffTag](ITarget& targets, int targetPos) {
			targets.GetTargetEntities().at(
				EffectsFactory::FindTargetingByType(targetType, targets.GetTargetEntities().size(), targetPos)
			).get().AddTag(debuffTag);
		};
	}
}


int EffectsFactory::FindTargetingByType(TargetType targetType, size_t teamSize, int targetPos)
{
	switch (targetType)
	{
	case TargetType::FRONT:
		return 1;
	case TargetType::SECOND:
		return 2;
	case TargetType::LAST:
		return static_cast<int>(teamSize - 1);
	case TargetType::TARGET:
		return targetPos;
	case TargetType::ALL:
	case TargetType::NONE:
	default:
		return -1;
	}

}