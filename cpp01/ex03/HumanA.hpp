#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
	private:
		HumanA();
		std::string name;
		Weapon weapon;
	public:
		HumanA(std::string name, Weapon& weapon);
		void setWeapon(Weapon& weapon);
		void attack();
};

#endif
