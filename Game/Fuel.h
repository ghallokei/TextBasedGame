#pragma once
#include "Player.h"
#include <string>
#include "Object.h"
class Fuel : public Object
{
public:
	Fuel();
	Fuel(std::string a_Name, bool a_IsAcquirable);
	Fuel(const Fuel& a_Fuel);

	~Fuel();

	Fuel& operator=(const Fuel& rhs);

	 std::string Description() const;

};
