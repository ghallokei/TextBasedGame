#pragma once

#include <string>
#include <vector>

#include "Object.h"
#include "Actor.h"
#include "Car.h"

class Player : public Actor
{
public:
	Player();
	Player(std::string a_Name, int a_MaxHealth, int food, Car& car);
	Player(const Player& a_Player);

	~Player();

	Player& operator=(const Player& rhs);

	bool DropItem(std::string a_ItemName);
	bool PickupItem(Object* a_Item);
	bool HasObject(std::string a_ItemName);
	void TakeHit(int a_Dmg);

	int GetFood();

	Car& GetCar();

	std::vector<Object*>& GetInventory();

	void SetFood(int newFood);

private:
	std::vector<Object*> m_Inventory;
	Car car;
	int food;
};
