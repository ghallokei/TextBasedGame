#pragma once

#include <string>
#include "Location.h" 
#include "Player.h"
class GasStation : public Location
{
public:
	GasStation();
	GasStation(std::string a_Name);
	GasStation(const GasStation& a_GastStation);

	~GasStation();

	GasStation& operator = (const GasStation& rhs);

	std::string Description(Player& player) const;
};

