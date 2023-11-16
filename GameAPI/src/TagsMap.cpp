#include "TagsMap.h"

std::map<std::string, std::function<void(ITarget& target)>> TagsMap::s_tagsMap = {
	{
		"Posioned",
		[](ITarget& target) {
			auto targetHero = target.GetTargetEntities().at(0);
			if (targetHero.get().GetHitPoints() > 0)
			{
				targetHero.get().ReceiveDamage(2);
			}
		}
	},
	{
		"Stunned",
		[](ITarget& target) {
			auto targetHero = target.GetTargetEntities().at(0);
			targetHero.get().GetTeam()->SetTeamCanConquer(false);
		}
	},
	{
		"Silienced",
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
	}

};
