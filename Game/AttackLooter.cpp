#include "AttackLooter.h"

#include "Player.h"

AttackLooter::AttackLooter() : Location()
{
}

AttackLooter::AttackLooter(std::string a_Name) : Location(a_Name)
{
}

AttackLooter::AttackLooter(const AttackLooter& a_AttackLooter) : Location(a_AttackLooter)
{
}

AttackLooter::~AttackLooter()
{
}

AttackLooter& AttackLooter::operator=(const AttackLooter&rhs)
{
	if (this == &rhs)
		return *this;

	Location::operator=(rhs);

	return *this;
}

std::string AttackLooter::Description(Player& player) const
{
	std::string descr = player.GetName()+ " decided to attack the looter who doesn't notice anything.\n";
	int randNum = std::rand() % 101;
	if (randNum > 50) {
		descr += player.GetName() + 
			" sneaked behind the looter and wrapped their arms around their neck.\nThe looter fliched and tried to get out of " 
			+ player.GetName() + "'s grasp but failed. \n" + player.GetName() + 
			" didn't budge until the looter dropped their arms limply.\nCongratulations," 
			+ player.GetName() + " killed the looter.\n\n";
	}
	else {
		player.SetHealth(player.GetHealth() - 40);
		descr += player.GetName() +
			" sneaked behind the looter tried to wrap their arms around the looter's neck.\nBut the looter heard "
			+ player.GetName() + " step in broken glass and turned around. \n" + player.GetName() +
			" swung their fist in panic and hit the wall instead.\nThe looter swung a metal pipe to"
			+ player.GetName() + "'s head and ran away.\n"
			+ player.GetName() + " took 40 damage.\n\n";
	}
	return descr;
}
