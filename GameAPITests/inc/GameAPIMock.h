#pragma once

#include "gmock/gmock.h"
#include "HeroesTeam.h"

class HeroTeamMock : public HeroesTeam
{
public:
	MOCK_METHOD(void, AddHero, (Hero));
	MOCK_METHOD(const Hero&, GetHero, (int), (const));
};

class HeroMock : public IHero
{
public:
	MOCK_METHOD(bool, ReceiveDamage, (int), (override));
	MOCK_METHOD(HeroClass, GetClass, (), (const, override));
	MOCK_METHOD(int, GetHitPoints, (), (const, override));
	MOCK_METHOD(int, GetTeamPriority, (), (const, override));
	MOCK_METHOD(void, SetPositionAssigned, (), (override));
};