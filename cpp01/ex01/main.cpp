#include "Zombie.hpp"

int main()
{
	Zombie* zombie_horde = Zombie::zombieHorde(10, "minjacho");
	for (int i = 0; i < 10; i++)
		zombie_horde[i].announce();
	delete zombie_horde;
}