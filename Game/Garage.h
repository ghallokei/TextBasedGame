#pragma once

#include <string>
#include "Location.h"
#include "Player.h"
class Garage : public Location
{
public:
	Garage();
	Garage(std::string a_Name);
	Garage(const Garage& a_Garage);

	~Garage();

	Garage& operator = (const Garage& rhs);

	std::string Description(Player& player) const;
};

