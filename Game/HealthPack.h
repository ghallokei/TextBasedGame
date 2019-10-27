#pragma once

#include <string>
#include "Object.h"
#include "Player.h"
class HealthPack : public Object
{
public:
	HealthPack();
	HealthPack(std::string a_Name, bool a_IsAcquirable);
	HealthPack(const HealthPack& a_Food);

	~HealthPack();

	HealthPack& operator=(const HealthPack& rhs);

	std::string Description() const;

};

