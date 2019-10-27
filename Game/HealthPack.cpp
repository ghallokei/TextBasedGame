#include "HealthPack.h"


#include "Player.h"
HealthPack::HealthPack()
	: Object()
{}

HealthPack::HealthPack(std::string a_Name, bool a_IsAcquirable)
	: Object(a_Name, a_IsAcquirable)
{}

HealthPack::HealthPack(const HealthPack& a_HealthPack)
	: Object(a_HealthPack)
{}

HealthPack::~HealthPack()
{}

HealthPack& HealthPack::operator=(const HealthPack& rhs)
{
	if (this == &rhs)
		return *this;

	Object::operator=(rhs);

	return *this;
}

std::string HealthPack::Description() const
{
	std::string descr = "" ;

	return descr;
}
