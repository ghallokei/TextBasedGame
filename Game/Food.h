#pragma once
#include "Player.h"
#include <string>
#include "Object.h"
class Food : public Object
{
public:
	Food();
	Food(std::string a_Name, bool a_IsAcquirable);
	Food(const Food& a_Food);

	~Food();

	Food& operator=(const Food& rhs);

	std::string Description() const;
};