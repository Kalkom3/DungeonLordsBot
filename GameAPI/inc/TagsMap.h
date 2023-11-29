#pragma once

#include <map>
#include <functional>
#include <string>

#include "HeroesTeam.h"

enum class TagsList
{
	STUNNED,
	POSIONED,
	SILIENCED,
	NO_HEAL
};

class TagsMap
{
public:
	static std::map<TagsList, std::function<void(ITarget& target)>> s_tagsMap;
	static std::string GetStringFromTag(TagsList tag);
};