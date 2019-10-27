#include "InspectSituation.h"

#include "Player.h"

InspectSituation::InspectSituation() : Location()
{
}


InspectSituation::InspectSituation(std::string a_Name) : Location(a_Name)
{
}

InspectSituation::InspectSituation(const InspectSituation& a_InspectSituation) : Location(a_InspectSituation)
{
}

InspectSituation::~InspectSituation()
{
}

InspectSituation&InspectSituation::operator=(const InspectSituation&rhs)
{
	if (this == &rhs)
		return *this;

	Location::operator=(rhs);

	return *this;
}

std::string InspectSituation::Description(Player& player) const
{
	std::string descr = "";

	if (this->m_Name == "Inspect gasstation")
	{
		descr = player.GetName() + " sees a looter inside the gasstation. It seems like they're waiting for something or someone.\n\n";
	}

	if (this->m_Name == "Inspect supermarket")
	{
		descr = "It looks like the supermarket is empty except for 2 littering zombies right infront of the store.\nIt seems like they won't go anywhere anytime soon.\n\n";
	}

	if (this->m_Name == "Inspect garage")
	{
		descr = "The garage looks abandoned. " + player.GetName() + " walks closer to the entrance and sees that there's no threat inside.\n\n";
	}

	return descr;
}
