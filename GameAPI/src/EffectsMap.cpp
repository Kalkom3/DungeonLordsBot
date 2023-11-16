#include "EffectsMap.h"
#include "EffectsFactory.h"
#include "TrapCard.h"
#include "TagsMap.h"


std::map<std::string, Effect> EffectsMap::s_effectsMap = {
	//===== Fire Wall =====
	{
		TrapCard::GetStringFromTrap(TrapsList::FIRE_WALL),
		Effect(
			EffectType::DAMAGE,
			EffectsFactory::CreateDamageEffect(TargetType::ALL, 1)
		)
	},
	{
		TrapCard::GetStringFromTrap(TrapsList::FIRE_WALL) + "2",
		Effect(
			EffectType::DAMAGE,
			EffectsFactory::CreateDamageEffect(TargetType::LAST, 1)
		)
	},
	//===== Rolling Bulder =====
	{
		TrapCard::GetStringFromTrap(TrapsList::ROLLING_BULDER),
		Effect(
			EffectType::DAMAGE,
			EffectsFactory::CreateDamageEffect(TargetType::FRONT, 3)
		)
	},
	//===== Falling Blade =====
	{
		TrapCard::GetStringFromTrap(TrapsList::FALLING_BLADE),
		Effect(
			EffectType::DAMAGE,
			EffectsFactory::CreateDamageEffect(TargetType::SECOND, 3)
		)
	},
	//===== Hole =====
	{
		TrapCard::GetStringFromTrap(TrapsList::HOLE),
		Effect(
			EffectType::GROUP_DEBUFF,
			EffectsFactory::CreateDebuffFunction(TargetType::FRONT, TagsList::STUNNED)
		)
	},
	{
		TrapCard::GetStringFromTrap(TrapsList::HOLE) + "2",
		Effect(
			EffectType::DAMAGE,
			EffectsFactory::CreateDamageEffect(TargetType::FRONT, 2)
		)
	},
	//===== Posioned Dart =====
	{
		TrapCard::GetStringFromTrap(TrapsList::POSIONED_DART),
		Effect(
			EffectType::TARGET_DEBUFF,
			EffectsFactory::CreateDebuffFunction(TargetType::TARGET, TagsList::POSIONED)
		)
	},
	{
		TrapCard::GetStringFromTrap(TrapsList::POSIONED_DART) + "2",
		Effect(
			EffectType::DAMAGE,
			EffectsFactory::CreateDamageEffect(TargetType::TARGET, 1)
		)
	},
	//===== Magic Dart =====
	{
		TrapCard::GetStringFromTrap(TrapsList::MAGIC_DART),
		Effect(
			EffectType::TARGET_DEBUFF,
			EffectsFactory::CreateDebuffFunction(TargetType::TARGET, TagsList::SILIENCED)
		)
	},
	{
		TrapCard::GetStringFromTrap(TrapsList::MAGIC_DART) + "2",
		Effect(
			EffectType::DAMAGE,
			EffectsFactory::CreateDamageEffect(TargetType::TARGET, 1)
		)
	},
	//===== Golden Ring =====
	{
		TrapCard::GetStringFromTrap(TrapsList::GOLDEN_RING),
		Effect(
			EffectType::DAMAGE,
			EffectsFactory::CreateDamageEffect(TargetType::ALL, 1)
		)
	},
	{
		TrapCard::GetStringFromTrap(TrapsList::GOLDEN_RING) + "2",
		Effect(
			EffectType::TARGET_DEBUFF,
			EffectsFactory::CreateDebuffFunction(TargetType::ALL, TagsList::STUNNED)
		)
	},
	//===== Imp Kamikaze =====
	{
		TrapCard::GetStringFromTrap(TrapsList::IMP_KAMIKAZE),
		Effect(
			EffectType::DAMAGE,
			EffectsFactory::CreateDamageEffect(TargetType::FRONT, 2)
		)
	},
	{
		TrapCard::GetStringFromTrap(TrapsList::IMP_KAMIKAZE) + "2",
		Effect(
			EffectType::DAMAGE,
			EffectsFactory::CreateDamageEffect(TargetType::ALL, 1)
		)
	},
	//===== Posioned Food =====
	{
		TrapCard::GetStringFromTrap(TrapsList::POSIONED_FOOD),
		Effect(
			EffectType::DAMAGE,
			EffectsFactory::CreateDamageEffect(TargetType::FRONT, 999)
		)
	},
};

