#include "ScavTrap.hpp"

int main()
{
	ScavTrap alpha;
	ScavTrap bravo("bravo");

	alpha.attack("bravo");
	bravo.takeDamage(alpha.getAttackDamage());
	alpha.printStatus();
	bravo.printStatus();

	ScavTrap alpha2(alpha);
	alpha2.printStatus();

	bravo.takeDamage(10);
	bravo.printStatus();
	bravo.beRepaired(10);
	bravo.printStatus();

	alpha.takeDamage(9);
	alpha.printStatus();
	alpha.beRepaired(10);
	alpha.printStatus();

	ClapTrap *scav = new ScavTrap("scav");
	scav->attack("scav");
	scav->takeDamage(scav->getAttackDamage());
	scav->attack("scav");
	scav->takeDamage(scav->getAttackDamage());
	scav->attack("scav");
	scav->takeDamage(scav->getAttackDamage());
	scav->attack("scav");
	scav->takeDamage(scav->getAttackDamage());
	scav->attack("scav");
	scav->takeDamage(scav->getAttackDamage());
	scav->attack("scav");
	scav->takeDamage(scav->getAttackDamage());
	scav->printStatus();
	delete scav;
}
