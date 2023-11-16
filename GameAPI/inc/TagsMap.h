#pragma once

#include <map>
#include <functional>
#include <string>

#include "HeroesTeam.h"

class TagsMap
{
public:
	static std::map<std::string, std::function<void(ITarget& target)>> s_tagsMap;
};