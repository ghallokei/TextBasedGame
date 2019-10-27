#pragma once

#include <string>
#include "Location.h"
#include "Player.h"
class StrangerEncounter : public Location
{
public:
	StrangerEncounter();
	StrangerEncounter(std::string a_Name);
	StrangerEncounter(const StrangerEncounter& a_StrangerEncounter);

	~StrangerEncounter();

	StrangerEncounter& operator = (const StrangerEncounter& rhs);

	std::string Description(Player& player) const;
};

