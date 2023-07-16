#pragma once

#include <vector>

class Hero;

class ITarget
{
public:
	virtual std::vector<std::reference_wrapper<Hero> > GetTargetEntities() = 0;

};
