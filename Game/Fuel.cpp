#include "Fuel.h"


#include "Player.h"
Fuel::Fuel()
	: Object()
{}

Fuel::Fuel(std::string a_Name, bool a_IsAcquirable)
	: Object(a_Name, a_IsAcquirable)
{}

Fuel::Fuel(const Fuel& a_Fuel)
	: Object(a_Fuel)
{}

Fuel::~Fuel()
{}

Fuel& Fuel::operator=(const Fuel& rhs)
{
	if (this == &rhs)
		return *this;

	Object::operator=(rhs);

	return *this;
}

std::string Fuel::Description() const
{
	std::string descr = "";

	return descr;
}
