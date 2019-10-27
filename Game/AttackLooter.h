#pragma once

#include <string>
#include "Location.h" 
#include "Player.h"
class AttackLooter : public Location
{
public:
	AttackLooter();
	AttackLooter(std::string a_Name);
	AttackLooter(const AttackLooter& a_AttackLooter);

	~AttackLooter();

	AttackLooter& operator = (const AttackLooter& rhs);

	std::string Description(Player& player) const;
};


