#include <string>
#include "Zombie.hpp"

/*
zombie를 만들고 zombie가 자기 자신에 대해 announce한다.
*/
void Zombie::randomChump(std::string name)
{
	Zombie new_zombie = Zombie(name);
	new_zombie.announce();
}
