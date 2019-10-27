#pragma once

class Car
{
public:
	Car();
	Car(int condition, int fuel);
	~Car();

	int GetCondition();
	int GetFuel();

	void SetCondition(int newCondition);
	void SetFuel(int newFuel);

private:
	int condition;
	int fuel;
};

