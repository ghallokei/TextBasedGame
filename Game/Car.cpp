#include "Car.h"

Car::Car() 
{

}

Car::Car(int condition, int fuel)
{
	this->condition = condition;
	this->fuel = fuel;
}


Car::~Car()
{
}

int Car::GetCondition() {
	return this->condition;
}

int Car::GetFuel() {
	return this->fuel;
}

void Car::SetCondition(int newCondition) {
	this->condition = newCondition;
}

void Car::SetFuel(int newFuel) {
	this->fuel = newFuel;
}
