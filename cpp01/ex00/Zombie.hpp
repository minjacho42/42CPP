#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		void announce();
		Zombie();
		Zombie(std::string name);
		static void randomChump(std::string name);
		static Zombie* newZombie(std::string name);
};

#endif
