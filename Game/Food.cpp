#include "Food.h"


#include "Player.h"
Food::Food()
	: Object()

{}

Food::Food(std::string a_Name, bool a_IsAcquirable)
	: Object(a_Name, a_IsAcquirable)
{}

Food::Food(const Food& a_Food)
	: Object(a_Food)
{}

Food::~Food()
{}

Food& Food::operator=(const Food& rhs)
{
	if (this == &rhs)
		return *this;

	Object::operator=(rhs);

	return *this;
}

std::string Food::Description() const
{
	std::string descr = "";

	return descr;
}
