#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	private:
		Weapon();
		std::string type;
	public:
		Weapon(const std::string& type);
		const std::string& getType();
		void setType(const std::string& type);
};

#endif
