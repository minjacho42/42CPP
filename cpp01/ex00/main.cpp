#include "Zombie.hpp"

// void checker() {system("leaks cpp01_ex00");}

int main()
{
	Zombie::randomChump("hello");
	Zombie* zombie2 = Zombie::newZombie("Zombie2");
	zombie2->announce();
	delete zombie2;
	// atexit(checker);
}
