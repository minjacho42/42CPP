# include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon): name(name), weapon(weapon) {}

void HumanA::setWeapon(const Weapon& weapon)
{
	this->weapon = weapon;
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << "\n";
}
