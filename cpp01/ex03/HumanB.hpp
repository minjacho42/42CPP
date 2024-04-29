#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:
		HumanB();
		std::string name;
		Weapon *weapon;
	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon& weapon);
		void setWeapon(Weapon& weapon);
		void attack();
};

#endif
