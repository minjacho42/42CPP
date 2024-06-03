#include "FragTrap.hpp"

int main()
{
	// FragTrap alpha;
	// FragTrap bravo("bravo");

	// alpha.attack("bravo");
	// bravo.takeDamage(alpha.getAttackDamage());
	// alpha.printStatus();
	// bravo.printStatus();

	// FragTrap alpha2(alpha);
	// alpha2.printStatus();

	// bravo.takeDamage(100);
	// bravo.printStatus();
	// bravo.beRepaired(10);
	// bravo.printStatus();

	// alpha.takeDamage(9);
	// alpha.printStatus();
	// alpha.beRepaired(10);
	// alpha.printStatus();

	// bravo.highFivesGuys();

	ClapTrap *frag = new FragTrap();
	frag->attack("frag");
	frag->takeDamage(frag->getAttackDamage());
	frag->attack("frag");
	frag->takeDamage(frag->getAttackDamage());
	frag->attack("frag");
	frag->takeDamage(frag->getAttackDamage());
	frag->attack("frag");
	frag->takeDamage(frag->getAttackDamage());
	frag->attack("frag");
	frag->takeDamage(frag->getAttackDamage());
	frag->printStatus();
	delete frag;
}
