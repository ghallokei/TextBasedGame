#include "SuperMarket.h"


#include "Player.h"
SuperMarket::SuperMarket() : Location()
{
}

SuperMarket::SuperMarket(std::string a_Name) : Location(a_Name)
{
}

SuperMarket::SuperMarket(const SuperMarket& a_SuperMarket) : Location(a_SuperMarket)
{
}


SuperMarket::~SuperMarket()
{
}

SuperMarket& SuperMarket::operator=(const SuperMarket& rhs) 
{
	if (this == &rhs)
		return *this;

	Location::operator=(rhs);

	return *this;
}

std::string SuperMarket::Description(Player& player) const
{
	std::string descr = "Once arriving to the supermarket, " + player.GetName() + " parked their car somewhere around the corner of the building.\n";
	return descr;
}