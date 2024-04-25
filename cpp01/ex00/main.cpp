#include "Zombie.hpp"

int main()
{
	Zombie::randomChump("hello");
	Zombie* zombie2 = Zombie::newZombie("Zombie2");
	zombie2->announce();
	system("leaks cpp01_ex00");
}
