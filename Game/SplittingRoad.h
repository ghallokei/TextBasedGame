#pragma once

#include <string>
#include "Location.h"
#include "Player.h"
class SplittingRoad : public Location
{
public:
	SplittingRoad();
	SplittingRoad(std::string a_Name);
	SplittingRoad(const SplittingRoad& a_SplittingRoad);

	~SplittingRoad();

	SplittingRoad& operator = (const SplittingRoad& rhs);

	std::string Description(Player& player) const;
};

