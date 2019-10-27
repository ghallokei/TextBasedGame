#pragma once

#include <string>
#include "Location.h"
#include "Player.h"
class SuperMarket : public Location
{
public:
	SuperMarket();
	SuperMarket(std::string a_Name);
	SuperMarket(const SuperMarket& a_Supermarket);

	~SuperMarket();

	SuperMarket& operator = (const SuperMarket& rhs);

	std::string Description(Player& player) const;
};

