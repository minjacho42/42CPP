# include "HumanB.hpp"

HumanB::HumanB(const std::string& name): name(name)
{
	this->weapon = NULL;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	if (!this->weapon)
		std::cout << this->name << " doesn't have weapon\n";
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << "\n";
}
