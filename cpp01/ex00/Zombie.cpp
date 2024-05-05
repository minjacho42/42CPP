# include "Zombie.hpp"

Zombie::Zombie(): name("anonymous") {}

Zombie::Zombie(std::string name): name(name) {}

Zombie::~Zombie()
{
	std::cout << this->name << " destructor called\n";
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}
