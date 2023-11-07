#include "EffectsFactory.h"
#include "Effect.h"
#include "Hero.h"
#include "DlLogger.h"

std::function<int(ITarget& target, int targetPos)> EffectsFactory::CreateDamageEffect(TargetType targetType, int damageAmount)
{
	if (targetType == TargetType::ALL)
	{
		return [damageAmount](ITarget& targets, int targetPos) -> int {
			int killCount = 0;
			for (int i = 0; i < targets.GetTargetEntities().size(); i++)
			{
				if (!targets.GetTargetEntities().at(i).get().ReceiveDamage(damageAmount))
				{
					i--;
					killCount++;
				}
			}
			return killCount;
		};
	}
	else
	{
		return [targetType, damageAmount](ITarget& targets, int targetPos) -> int {
			int killCount = 0;
			auto target = targets.GetTargetEntities().at(
				EffectsFactory::FindTargetingByType(targetType, targets.GetTargetEntities().size(), targetPos)
			);
			if (!target.get().ReceiveDamage(damageAmount))
			{
				killCount++;
			}
			return killCount;
		};
	}

}

std::function<int(ITarget& target, int targetPos)> EffectsFactory::CreateDebuffFunction(TargetType targetType, std::string debuffTag)
{
	if (targetType == TargetType::ALL)
	{
		return [debuffTag](ITarget& targets, int targetPos) -> int {
			targets.GetTargetEntities().at(0).get().AddTag(debuffTag);
			return 0;
		};
	}
	else
	{
		return [targetType, debuffTag](ITarget& targets, int targetPos) -> int {
			targets.GetTargetEntities().at(
				EffectsFactory::FindTargetingByType(targetType, targets.GetTargetEntities().size(), targetPos)
			).get().AddTag(debuffTag);
			return 0;
		};
	}
}


int EffectsFactory::FindTargetingByType(TargetType targetType, size_t teamSize, int targetPos)
{
	switch (targetType)
	{
	case TargetType::FRONT:
		return 0;
	case TargetType::SECOND:
		return 1;
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