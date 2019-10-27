#include "StrangerEncounter.h"

#include "Player.h"

StrangerEncounter::StrangerEncounter() : Location()
{
}

StrangerEncounter::StrangerEncounter(std::string a_Name) : Location(a_Name)
{
}

StrangerEncounter::StrangerEncounter(const StrangerEncounter& a_StrangerEncounter) : Location(a_StrangerEncounter)
{
}

StrangerEncounter::~StrangerEncounter()
{
}

StrangerEncounter& StrangerEncounter::operator=(const StrangerEncounter& rhs)
{
	if (this == &rhs)
		return *this;

	Location::operator=(rhs);

	return *this;
}

std::string StrangerEncounter::Description(Player& player) const
{
	std::string descr = "While driving, " + player.GetName() + " came across a person who's trying to get a lift from them.\nHe looks lost and in need for help.\nWill " + player.GetName() + " help them?\n\n";
	return descr;
}
