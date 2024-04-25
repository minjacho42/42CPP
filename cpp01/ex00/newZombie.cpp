#include <string>
#include "Zombie.hpp"

/*
It creates a zombie, name it, and return it so you can use it outside of the function
scope.
*/
Zombie* Zombie::newZombie(std::string name)
{
	Zombie* new_zombie = new Zombie(name);
	new_zombie->announce();
	return new_zombie;
}
