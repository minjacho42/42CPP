#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		HumanA();
		std::string name;
		Weapon& weapon;
	public:
		HumanA(const std::string& name, Weapon& weapon);
		void setWeapon(const Weapon& weapon);
		void attack();
};

#endif
