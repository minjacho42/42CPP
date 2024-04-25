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
		void SetName(std::string name);
		static Zombie* zombieHorde(int N, std::string name);
};

#endif
