#include "SpellsMap.h"
#include "TrapCard.h"
#include "MonsterCard.h"
#include "SpellCard.h"
#include "TagsMap.h"


std::map<std::string, SpellCard> SpellsMap::s_spellsMap = {
	{
		SpellCard::GetStringFromSpell(SpellList::MAGIC_SHIELD),
		SpellCard(
		SpellType::BUFF,
		std::make_unique<BuffSpellEffect>(
			[](HeroTargets target) {
			}),
		1, 
		true
		)
	}
};


