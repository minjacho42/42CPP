#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		static const unsigned int default_hit_point = 100;
		static const unsigned int default_energy_point = 100;
		static const unsigned int default_attack_damage = 30;
		bool	hasEnoughPoint(void);
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& instance);
		~FragTrap();
		FragTrap& operator=(const FragTrap& rvalue);

		void	attack(const std::string& target);
		void	highFivesGuys(void);

		void	printStatus(void);
};

#endif
