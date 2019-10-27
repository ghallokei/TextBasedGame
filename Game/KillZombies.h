#pragma once

#include <string>
#include "Location.h"
class KillZombies : public Location
{
public:
	KillZombies();
	KillZombies(std::string a_Name);
	KillZombies(const KillZombies& a_KillZombies);

	~KillZombies();

	KillZombies& operator = (const KillZombies& rhs);

	std::string Description(Player& player) const;
};

