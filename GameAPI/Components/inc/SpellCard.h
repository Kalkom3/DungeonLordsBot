#pragma once

#include "SpellEffect.h"

enum class SpellType 
{
	BUFF,
	OFFENCE,
	RESOURCE
};

enum class SpellList
{
	WORD_OF_PEACE,
	SUGGESTION,
	MAGIC_SHIELD,
	INVISIBILITY,
	DETECT_EVIL,
	FIST_OF_JUSTICE,
	DETECT_TREASURE,
	GRAFFITI,
	FIREBALL,
	//------ 2. year ------
	AURA_OF_FEAR,
	METAMORPHOSIS,
	BLIND_RAGE,
	CREATE_FOOR,
	ILLUSION,
	SONG_OF_COURAGE,
	REGENERATION,
	MAGIC_KEY,
	DIMENSIONAL_GATE

};

class SpellCard
{
public:
	SpellCard(SpellType type, std::unique_ptr<SpellEffect> effect, int fatigue, bool isFast);
	int GetFatigue() const;
	SpellType GetSpellType() const;
	bool IsFast();
	void CastSpell(ITarget& target);

	static std::string GetStringFromSpell(SpellList spell);
private:
	std::string m_name = "";
	std::unique_ptr<SpellEffect>m_effect;
	int m_fatigue = 0;
	bool m_fastSpell = false;
	SpellType m_type;
};

