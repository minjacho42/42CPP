#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		static const unsigned int default_hit_point = 100;
		static const unsigned int default_energy_point = 50;
		static const unsigned int default_attack_damage = 20;
		bool	hasEnoughPoint(void);
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& instance);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap& rvalue);

		void	attack(const std::string& target);
		void	guardGate(void);

		void	printStatus(void);
};

#endif
