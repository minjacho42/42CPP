# include "Zombie.hpp"

Zombie::Zombie(): name("anonymous") {}

Zombie::Zombie(std::string name): name(name) {}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::SetName(std::string name)
{
	this->name = name;
}
