#include "EffectsFactory.h"
#include "Effect.h"
#include "DlLogger.h"
#include "HeroesTeam.h"

std::function<int(ITarget& target, int targetPos)> EffectsFactory::CreateDamageEffect(TargetType targetType, int damageAmount)
{
	if (targetType == TargetType::ALL)
	{
		return [damageAmount](ITarget& targets, int targetPos)  -> int {
			int killCount = 0;
			auto targetsVec = std::get<HeroTargets>(targets.GetTargetEntities()).get().GetHeroes();
			for (int i = 0; i < targetsVec.size(); i++)
			{
				if (!targetsVec.at(i).ReceiveDamage(damageAmount))
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
			auto targetsVec = std::get<HeroTargets>(targets.GetTargetEntities()).get().GetHeroes();

			auto target = targetsVec.at(
				EffectsFactory::FindTargetingByType(targetType, targetsVec.size(), targetPos)
			);
			int effectiveDamage = damageAmount <= 8 ? damageAmount : target.GetHitPoints();
			if (!target.ReceiveDamage(effectiveDamage))
			{
				killCount++;
			}
			return killCount;
		};
	}

}

std::function<int(ITarget& target, int targetPos)> EffectsFactory::CreateDebuffFunction(TargetType targetType, TagsList debuffTag)
{
	if (targetType == TargetType::ALL)
	{
		return [debuffTag](ITarget& targets, int targetPos) -> int {
			auto targetsVec = std::get<HeroTargets>(targets.GetTargetEntities()).get().GetHeroes();
			targetsVec.at(0).AddTag(debuffTag);
			return 0;
		};
	}
	else
	{
		return [targetType, debuffTag](ITarget& targets, int targetPos) -> int {
			auto targetsVec = std::get<HeroTargets>(targets.GetTargetEntities()).get().GetHeroes();
			targetsVec.at(
				EffectsFactory::FindTargetingByType(targetType, targetsVec.size(), targetPos)
			).AddTag(debuffTag);
			return 0;
		};
	}
}

std::function<void(ITarget& target)> EffectsFactory::CreateBuffSpellFunction(TargetType targetType, TagsList buffTag)
{
	return std::function<void(ITarget & target)>();
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