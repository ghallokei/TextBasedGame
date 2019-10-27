#include "Garage.h"


#include "Player.h"
Garage::Garage() : Location()
{
}

Garage::Garage(std::string a_Name) : Location(a_Name)
{
}

Garage::Garage(const Garage& a_Garage) : Location(a_Garage)
{
}

Garage::~Garage()
{
}

Garage& Garage::operator=(const Garage&rhs)
{
	if (this == &rhs)
		return *this;

	Location::operator=(rhs);

	return *this;
}

std::string Garage::Description(Player& player) const
{
	std::string descr = player.GetName() + " arrived at the gasstation.\n";
	return descr;
}
