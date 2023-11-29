#include "TagsMap.h"

std::map<TagsList, std::function<void(ITarget& target)>> TagsMap::s_tagsMap = {
	{
		TagsList::POSIONED,
		[](ITarget& target) {
			auto targetHero = target.GetTargetEntities().at(0);
			if (targetHero.get().GetHitPoints() > 0)
			{
				targetHero.get().SetPosioned(2);
			}
		}
	},
	{
		TagsList::STUNNED,
		[](ITarget& target) {
			auto targetHero = target.GetTargetEntities().at(0);
			targetHero.get().GetTeam()->SetTeamCanConquer(false);
		}
	},
	{
		TagsList::SILIENCED,
		[](ITarget& target) {
			auto targetHero = target.GetTargetEntities().at(0);
			if (targetHero.get().GetClass() == HeroClass::MAGE)
			{
				targetHero.get().GetTeam()->SetTeamCanCast(false);
			}
			if (targetHero.get().GetClass() == HeroClass::PRIEST)
			{
				targetHero.get().GetTeam()->SetTeamCanHeal(false);
			}
		}
	},
	{
		TagsList::NO_HEAL,
		[](ITarget& target) {
			auto targetHero = target.GetTargetEntities().at(0);
			targetHero.get().GetTeam()->SetTeamCanHeal(false);
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
