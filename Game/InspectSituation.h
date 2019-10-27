#pragma once

#include <string>
#include "Location.h"
#include "Player.h"
class InspectSituation : public Location
{
public:
	InspectSituation();
	InspectSituation(std::string a_Name);
	InspectSituation(const InspectSituation& a_InspectSituation);

	~InspectSituation();

	InspectSituation& operator = (const InspectSituation& rhs);

	std::string Description(Player& player) const;
};

