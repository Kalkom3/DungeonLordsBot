#include "SpellCard.h"

SpellCard::SpellCard(SpellType type, std::unique_ptr<SpellEffect>effect, int fatigue, bool isFast) :
	m_type(type), m_effect(std::move(effect)), m_fatigue(fatigue), m_fastSpell(isFast)
{
}

int SpellCard::GetFatigue() const
{
	return m_fatigue;
}

SpellType SpellCard::GetSpellType() const
{
	return m_type;
}

bool SpellCard::IsFast()
{
	return m_fastSpell;
}

void SpellCard::CastSpell(ITarget& target)
{
	(*m_effect.get())(target);
}

std::string SpellCard::GetStringFromSpell(SpellList spell)
{
	switch (spell)
	{
	case SpellList::WORD_OF_PEACE:
		return "WORD_OF_PEACE";
		break;
	case SpellList::SUGGESTION:
		return "SUGGESTION";
		break;
	case SpellList::MAGIC_SHIELD:
		return "MAGIC_SHIELD";
		break;
	case SpellList::INVISIBILITY:
		return "INVISIBILITY";
		break;
	case SpellList::DETECT_EVIL:
		return "DETECT_EVIL";
		break;
	case SpellList::FIST_OF_JUSTICE:
		return "FIST_OF_JUSTICE";
		break;
	case SpellList::DETECT_TREASURE:
		return "DETECT_TREASURE";
		break;
	case SpellList::GRAFFITI:
		return "GRAFFITI";
		break;
	case SpellList::FIREBALL:
		return "FIREBALL";
		break;
	case SpellList::AURA_OF_FEAR:
		return "AURA_OF_FEAR";
		break;
	case SpellList::METAMORPHOSIS:
		return "METAMORPHOSIS";
		break;
	case SpellList::BLIND_RAGE:
		return "BLIND_RAGE";
		break;
	case SpellList::CREATE_FOOR:
		return "CREATE_FOOR";
		break;
	case SpellList::ILLUSION:
		return "ILLUSION";
		break;
	case SpellList::SONG_OF_COURAGE:
		return "SONG_OF_COURAGE";
		break;
	case SpellList::REGENERATION:
		return "REGENERATION";
		break;
	case SpellList::MAGIC_KEY:
		return "MAGIC_KEY";
		break;
	case SpellList::DIMENSIONAL_GATE:
		return "DIMENSIONAL_GATE";
		break;
	default:
		break;
	}
}
