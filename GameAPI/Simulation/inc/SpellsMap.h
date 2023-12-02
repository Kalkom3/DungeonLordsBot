#pragma once

#include <map>
#include <string>

class SpellCard;

class SpellsMap
{
public:
	static std::map<std::string, SpellCard> s_spellsMap;
};