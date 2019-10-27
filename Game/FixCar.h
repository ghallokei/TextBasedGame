#pragma once

#include <string>
#include "Location.h"
class FixCar : public Location
{
public:
	FixCar();
	FixCar(std::string a_Name);
	FixCar(const FixCar& a_FixCar);

	~FixCar();

	FixCar& operator = (const FixCar& rhs);

	std::string Description(Player& player) const;
};

