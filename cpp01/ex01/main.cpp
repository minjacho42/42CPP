#include "Zombie.hpp"

// void checker() {system("leaks cpp01_ex01");}
Zombie* zombieHorde(int N, std::string name);

int main()
{
	Zombie* zombie_horde = zombieHorde(10, "minjacho");
	for (int i = 0; i < 10; i++)
		zombie_horde[i].announce();
	delete[] zombie_horde;
	// atexit(checker);
}
