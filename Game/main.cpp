#include <iostream>

#include "Constants.h"

#include "Player.h"

#include "GasStation.h"
#include "SuperMarket.h"
#include "Garage.h"

#include "StrangerEncounter.h"
#include "SplittingRoad.h"

#include "KillZombies.h"
#include "FixCar.h"
#include "InspectSituation.h"
#include "AttackLooter.h"

#include "Fuel.h"
#include "Food.h"
#include "HealthPack.h"

#include "Map.h"

using namespace std;

void welcome(Player& a_Player);
void printInventory(vector<Object*>& a_Invent);
void initMap(Map& a_Map);
void run(Map& a_Map, Player& a_Player);
std::string showMenu(Map& a_Map, vector<std::string>& a_Menu);
void showDirections(Map& a_Map, vector<std::string>& a_Menu);
void quit();
void displayStats(Player& player);

int main()
{
	int mapWidth = MAPWIDTH;
	int mapHeigth = MAPHEIGHT;
	int yStartPos = 0;
	int xStartPos = 3;

	cout << "Before you can start your adventure, please enter your name.\n\n";

	string name = "";
	
	bool error = false;
	do
	{
		error = false;
		if (!error)
		{
			cout << "Please enter your name:\n";
		}
		else
		{
			cout << "Something went wrong, would you please enter your name:\n";
		}
		cin >> name;
	} while (error || name == "");

	Car* car = new Car(90, 50);
	Player* player = new Player(name, 100, 40, *car);

	welcome(*player);

	vector< vector<Location*> > m(mapHeigth, vector<Location*>(mapWidth));
	Map map(m, yStartPos, xStartPos);
	
	initMap(map);
	
	run(map, *player);

	quit();
	return 0;
}

void welcome(Player& player)
{
	system("CLS");
	displayStats(player);

	string output = "A few months ago, a huge virus breakout started.\n";
	output += "The people who got infected started to become agressive and the only way to spread the virus is though a bite from one, or through blood.\n";
	output += "For months " + player.GetName() + " has been going from place to place to find more resources.\n";
	output += "Luckily " + player.GetName() + " found a car a few weeks ago that was still fully functional. \n";
	output += "After looting a house " + player.GetName() + " made sure they took everthing, " + player.GetName() + " decided to leave.\n";
	cout << output << endl;
	
	printInventory(player.GetInventory());

	cout << "\nPress enter to continue...";
	cin.ignore(cin.rdbuf()->in_avail() + 1);
}

void printInventory(vector<Object*>& a_Invent)
{

	int size = a_Invent.size();
	cout << "There are " << size << " items in your inventory.\n";
	if (size > 0)
	{
		cout << "These are:\n";
		for (int i = 0; i < size; i++)
		{
			cout << a_Invent[i]->GetName() << endl;
		}
	}
}

void displayStats(Player& player) {
	cout << "-----------------------------------" << endl;
	cout << player.GetName() + "'s stats:\n";
	cout << "Food: " << player.GetFood() << "\n";
	cout << "Health:" << player.GetHealth() << "\n";
	cout << "Car condition: " << player.GetCar().GetCondition() << "\n";
	cout << "Fuel: " << player.GetCar().GetFuel() << "\n";
	cout << "-----------------------------------\n" << endl;
}

void initMap(Map& a_Map)
{

	StrangerEncounter* strangerEncounter = new StrangerEncounter("The road");
	a_Map.AddLocation(*strangerEncounter, 0, 3);	

	SplittingRoad* splittingRoad = new SplittingRoad("Splitting lane");
	a_Map.AddLocation(*splittingRoad, 1, 3);

	GasStation* gasStation = new GasStation("Gasstation");
	a_Map.AddLocation(*gasStation, 1, 2);

	InspectSituation* inspectSituationGAS = new InspectSituation("Inspect gasstation");
	a_Map.AddLocation(*inspectSituationGAS, 1, 1);
	Fuel* gasFuel = new Fuel("Fuel",true);
	inspectSituationGAS->AddObject((Object*)gasFuel);

	SuperMarket* superMarket = new SuperMarket("Supermarket");
	a_Map.AddLocation(*superMarket, 2, 3);

	InspectSituation* inspectSituationSUPER = new InspectSituation("Inspect supermarket");
	a_Map.AddLocation(*inspectSituationSUPER, 3, 3);
	Food* food = new Food("Food", true);
	inspectSituationSUPER->AddObject((Object*)food);

	Garage* garage = new Garage("Garage");
	a_Map.AddLocation(*garage, 1, 4);

	InspectSituation* inspectSituationGAR = new InspectSituation("Inspect garage");
	a_Map.AddLocation(*inspectSituationGAR, 1, 5);
	HealthPack* healthPack = new HealthPack("Health Pack", true);
	inspectSituationGAR->AddObject((Object*)healthPack);

	AttackLooter* attackLooter = new AttackLooter("Attack the looter");
	a_Map.AddLocation(*attackLooter, 0, 1);

	FixCar* fixCar = new FixCar("Fix the car");
	a_Map.AddLocation(*fixCar, 0, 5);

	KillZombies* killZombies = new KillZombies("Get rid of the zombies");
	a_Map.AddLocation(*killZombies, 4, 3);
}

void run(Map& a_Map, Player& a_Player)
{
	std::vector<string> menuItems;
	std::string choice;


	do
	{
		system("CLS");

		std::string descr = a_Map.GetLocation().Description(a_Player);
		displayStats(a_Player);
		 
		cout << descr;
		choice = showMenu(a_Map, menuItems);

		int x = a_Map.GetPosition().XPos;
		int y = a_Map.GetPosition().Ypos;

		if (a_Map.GetNorth() == 1 && choice == a_Map.GetMap()[y + 1][x]->GetName())
			a_Map.Move("Go North");

		if (a_Map.GetEast()== 1 && choice == a_Map.GetMap()[y][x + 1]->GetName())
			a_Map.Move("Go East");

		if (a_Map.GetSouth()== 1 && choice == a_Map.GetMap()[y - 1][x]->GetName())
			a_Map.Move("Go South");

		if (a_Map.GetWest() == 1 && choice == a_Map.GetMap()[y][x - 1]->GetName())
			a_Map.Move("Go West");



		if (choice == "Help him")
		{
			system("CLS");
			a_Player.SetFood(a_Player.GetFood() + 20);

			displayStats(a_Player);
			cout << "\"Rough times out there. Step in, I'll drop you off somewhere safer.\"";
			cout << a_Player.GetName() << " said.\n\n";

			cout << "\"Thank you for the ride. I lost my brother a while ago and can't seem to find him....\nYou are a life saver!\" The stranger said.\n\n";
			cout << "Before Leaving, as grattitude the stranger gave you +20 food.\n\n";

			cout << "\nPress enter to continue...";
			cin.ignore(cin.rdbuf()->in_avail() + 1);

			a_Map.Move("Go North");
		}

		if (choice == "Keep driving")
		{
			system("CLS");

			displayStats(a_Player);
			cout << a_Player.GetName() << " looked the stranger in the eye and decided to keep driving.\n";
			cout << "In the rear mirror " << a_Player.GetName() << " sees the stranger running from a few littering zombies that got attracted by the sounds their car made.\n\n";

			cout << "\nPress enter to continue...";
			cin.ignore(cin.rdbuf()->in_avail() + 1);

			a_Map.Move("Go North");
		}

		if (choice == "Search.")
		{
			system("CLS");

			displayStats(a_Player);
			
			if (a_Map.GetLocation().GetObjects()[0]->GetName() == "Fuel")
			{
				a_Player.GetCar().SetFuel(a_Player.GetCar().GetFuel() + 35);
				cout << endl  << a_Player.GetName() << " has found a canister of fuel.\nThe car has 35 more fuel.\n";
			}
			
			if (a_Map.GetLocation().GetObjects()[0]->GetName() == "Food")
			{
				a_Player.SetFood(a_Player.GetFood() + 20);
				cout << endl << a_Player.GetName() << " has found a few cans of food.\n" << a_Player.GetName() << " has obtained +20 food.\n";
			}

			if (a_Map.GetLocation().GetObjects()[0]->GetName() == "Health Pack")
			{
				a_Player.SetHealth(100); 
				cout << endl << a_Player.GetName() << " has found a healthpack and regained full health.\c";
			}

			cout << "\nPress enter to continue...";
			cin.ignore(cin.rdbuf()->in_avail() + 1);
		}

		if (a_Player.GetHealth() <= 0)
		{
			a_Player.SetIsAlive(false);
		}

	} while (choice != "Exit." && a_Player.IsAlive());
}

std::string showMenu(Map& a_Map, vector<std::string>& a_Menu)
{
	int choice;
	a_Menu.clear();
	a_Menu.shrink_to_fit();

	showDirections(a_Map, a_Menu);

	if (a_Map.GetLocation().CheckForItems())
	{
		bool acquirableItems = false;
		vector<Object*> list = a_Map.GetLocation().GetObjects();
		for (unsigned int i = 0; i < list.size(); i++)
		{
			if (list[i]->IsAcquirable())
			{
				acquirableItems = true;
			}
		}
		if (acquirableItems)
			a_Menu.push_back("Search.");
	}

	a_Menu.push_back("Exit.");

	bool error = false;
	do
	{
		for (unsigned int i = 0; i < a_Menu.size(); i++)
		{
			cout << i + 1 << " - " << a_Menu[i] << endl;
		}

		cout << "\n\nMake a choice and press enter to continue (1 - " << a_Menu.size() << "):\n";

		cin >> choice;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			error = true;
		}
	} while (error || choice < 1 || choice > a_Menu.size());

	return a_Menu[choice - 1];
}

void showDirections(Map& a_Map, vector<std::string>& a_Menu)
{
	a_Map.AllowedDirections();
	int x = a_Map.GetPosition().XPos;
	int y = a_Map.GetPosition().Ypos;

	string locName = a_Map.GetLocation().GetName();

	if (locName == "The road") {
		a_Menu.push_back("Help him");
		a_Menu.push_back("Keep driving");
	} 
	else {
	
	if (a_Map.GetNorth() == 1) {
		string directionName = a_Map.GetMap()[y+1][x]->GetName();
		a_Menu.push_back(directionName);
	}

	if (a_Map.GetEast() == 1) {
		string directionName = a_Map.GetMap()[y][x+1]->GetName();
		a_Menu.push_back(directionName);
	}
		
	if (a_Map.GetSouth() == 1) {
		string directionName = a_Map.GetMap()[y-1][x]->GetName();
		a_Menu.push_back(directionName);
	}
		
	if (a_Map.GetWest() == 1) {
		string directionName = a_Map.GetMap()[y][x - 1]->GetName();
		a_Menu.push_back(directionName);
	}

	}	
}

void quit()
{
	system("CLS");
	cout << "Thank you for playing!! :) \n";
	cout << "Press enter to exit the game...";
	cin.ignore(cin.rdbuf()->in_avail() + 1);
}