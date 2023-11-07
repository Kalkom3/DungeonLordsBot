#pragma once

#include <map>
#include <functional>
#include <string>

class ITarget;

class TagsMap
{
public:
	static std::map<std::string, std::function<void(ITarget& target)>> s_tagsMap;
	static int test();
};