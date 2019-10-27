#include "KillZombies.h"


#include "Player.h"
KillZombies::KillZombies() : Location()
{
}

KillZombies::KillZombies(std::string a_Name) : Location(a_Name)
{
}

KillZombies::KillZombies(const KillZombies& a_KillZombies) : Location(a_KillZombies)
{
}

KillZombies::~KillZombies()
{
}

KillZombies& KillZombies::operator=(const KillZombies&rhs)
{
	if (this == &rhs)
		return *this;

	Location::operator=(rhs);

	return *this;
}

std::string KillZombies::Description(Player& player) const
{
	std::string descr = player.GetName()+ " decided to Kill the littering zombies.\n";
	int randNum = std::rand() % 101;
	if (randNum > 50) {
		descr += player.GetName() + 
			" waited for the zombies walk away from eachother.\nOnce one of the zombie was further away form the other, " 
			+ player.GetName() + " grabbed it from behind and proceeded to twist it's head.\nAfter a satisfying snap and a limp zombie in " 
			+ player.GetName() + "'s arms, "
			+ player.GetName() + " dropped the body and did the same to the other zombie.\nCongratulations," 
			+ player.GetName() + " killed the zombies.\n\n";
			
	}
	else {
		player.SetHealth(player.GetHealth() - 40);
		descr += player.GetName() +
			" sneaked behind a zombie and tried to wrap their arms around the zombie's neck.\nWhile trying to kill it, the other zombie sees "
			+ player.GetName() + " and swung at "
			+ player.GetName() + "'s face. "
			+ player.GetName() + " flinched but didn't let go from the zombie until it was dead.\nThen "
			+ player.GetName() + " proceeded to kill the other zombie quickly.\n"
			+ player.GetName() + " took 40 damage.\n\n";
	}
	return descr;
}

