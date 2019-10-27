#include "GasStation.h"


#include "Player.h"
GasStation::GasStation() : Location()
{
}

GasStation::GasStation(std::string a_Name) : Location(a_Name)
{
}

GasStation::GasStation(const GasStation& a_GasStation) : Location(a_GasStation)
{
}

GasStation::~GasStation()
{
}

GasStation& GasStation::operator=(const GasStation& rhs)
{
	if (this == &rhs)
		return *this;

	Location::operator=(rhs);

	return *this;
}

std::string GasStation::Description(Player& player) const
{
	std::string descr = "Once arriving at the gasstation " + player.GetName() + " parked the car and stepped out.\n";
	return descr;
}

