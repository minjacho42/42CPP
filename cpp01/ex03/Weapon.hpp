#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	private:
		Weapon();
		std::string type;
	public:
		Weapon(std::string type);
		std::string getType();
		void setType(std::string type);
};

#endif
