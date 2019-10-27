#include "SplittingRoad.h"


#include "Player.h"
SplittingRoad::SplittingRoad() : Location()
{
}

SplittingRoad::SplittingRoad(std::string a_Name) : Location(a_Name)
{
}

SplittingRoad::SplittingRoad(const SplittingRoad& a_SplittingRoad) : Location(a_SplittingRoad)
{
}

SplittingRoad::~SplittingRoad()
{
}

SplittingRoad& SplittingRoad::operator=(const SplittingRoad& rhs) 
{
	if (this == &rhs)
		return *this;

	Location::operator=(rhs);

	return *this;
}

std::string SplittingRoad::Description(Player& player) const
{
	std::string descr = "After driving for a while " + player.GetName() + " came across a splitting lane.\nGo to:\n";
	return descr;
}
