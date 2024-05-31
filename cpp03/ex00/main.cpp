#include "ClapTrap.hpp"

int main()
{
	ClapTrap alpha;
	ClapTrap bravo("bravo");

	alpha.attack("bravo");
	bravo.takeDamage(0);
	alpha.printStatus();
	bravo.printStatus();

	ClapTrap alpha2(alpha);
	alpha2.printStatus();

	bravo.takeDamage(10);
	bravo.printStatus();
	bravo.beRepaired(10);
	bravo.printStatus();

	alpha.takeDamage(9);
	alpha.printStatus();
	alpha.beRepaired(10);
	alpha.printStatus();
}
