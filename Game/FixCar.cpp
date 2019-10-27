#include "FixCar.h"


#include "Player.h"
FixCar::FixCar() : Location()
{
}

FixCar::FixCar(std::string a_Name) : Location(a_Name)
{
}

FixCar::FixCar(const FixCar& a_FixCar) : Location(a_FixCar)
{
}

FixCar::~FixCar()
{
}

FixCar& FixCar::operator=(const FixCar&rhs)
{
	if (this == &rhs)
		return *this;

	Location::operator=(rhs);

	return *this;
}

std::string FixCar::Description(Player& player) const
{
	std::string descr = player.GetName()+ " found tools to repair the car.\nThe car is now fully functional again.\n\n";
	player.GetCar().SetCondition(100);
	return descr;
}

