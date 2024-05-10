#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);
// void checker() {system("leaks cpp01_ex00");}

int main()
{
	randomChump("hello");
	Zombie* zombie2 = newZombie("Zombie2");
	zombie2->announce();
	delete zombie2;
	// atexit(checker);
}
