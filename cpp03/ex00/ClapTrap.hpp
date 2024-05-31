#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	private:
		std::string		name;
		unsigned int	hit_point;
		unsigned int	energy_point;
		unsigned int	attack_damage;

		static const unsigned int default_hit_point = 10;
		static const unsigned int default_energy_point = 10;
		static const unsigned int default_attack_damage = 0;

		bool	hasEnoughPoint(void);
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap& instance);
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap& rvalue);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string		getName(void);
		unsigned int	getHitPoint(void);
		unsigned int	getEnergyPoint(void);
		unsigned int	getAttackDamage(void);

		void	printStatus(void);
};

#endif
