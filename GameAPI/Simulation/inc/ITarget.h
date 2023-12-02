#pragma once

#include <vector>
#include <variant>

class HeroesTeam;
class Monster;

using PossibleTargets = std::variant<std::reference_wrapper<HeroesTeam>, std::reference_wrapper<Monster> >;
using HeroTargets = std::reference_wrapper<HeroesTeam>;
using MonstersTargets = std::reference_wrapper<Monster>;

class ITarget
{
public:
	virtual PossibleTargets GetTargetEntities() = 0;

};

