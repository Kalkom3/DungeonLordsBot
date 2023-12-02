#include "TagsMap.h"

std::map<TagsList, std::function<void(ITarget& target)>> TagsMap::s_tagsMap = {
	{
		TagsList::POSIONED,
		[](ITarget& target) {
			auto targetsVec = std::get<HeroTargets>(target.GetTargetEntities()).get().GetHeroes();
			auto targetHero = targetsVec.at(0);
			if (targetHero.GetHitPoints() > 0)
			{
				targetHero.SetPosioned(2);
			}
		}
	},
	{
		TagsList::STUNNED,
		[](ITarget& target) {
			auto targetsVec = std::get<HeroTargets>(target.GetTargetEntities()).get().GetHeroes();
			auto targetHero = targetsVec.at(0);
			targetHero.GetTeam()->SetTeamCanConquer(false);
		}
	},
	{
		TagsList::SILIENCED,
		[](ITarget& target) {
			auto targetsVec = std::get<HeroTargets>(target.GetTargetEntities()).get().GetHeroes();
			auto targetHero = targetsVec.at(0);
			if (targetHero.GetClass() == HeroClass::MAGE)
			{
				targetHero.GetTeam()->SetTeamCanCast(false);
			}
			if (targetHero.GetClass() == HeroClass::PRIEST)
			{
				targetHero.GetTeam()->SetTeamCanHeal(false);
			}
		}
	},
	{
		TagsList::NO_HEAL,
		[](ITarget& target) {
			auto targetsVec = std::get<HeroTargets>(target.GetTargetEntities()).get().GetHeroes();
			auto targetHero = targetsVec.at(0);
			targetHero.GetTeam()->SetTeamCanHeal(false);
		}
	}

};

std::string TagsMap::GetStringFromTag(TagsList tag)
{
	switch (tag)
	{
	case TagsList::STUNNED:
			return "Stunned";
		break;
	case TagsList::POSIONED:
		return "Posioned";
		break;
	case TagsList::SILIENCED:
		return "Silienced";
		break;
	case TagsList::NO_HEAL:
		return "No_Heal";
		break;
	default:
		return "ERROR TYPE";
		break;
	}
}
