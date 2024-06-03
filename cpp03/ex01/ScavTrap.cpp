# include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default constructor called [ScavTrap]" << std::endl;
	this->hit_point = default_hit_point;
	this->energy_point = default_energy_point;
	this->attack_damage = default_attack_damage;
}

ScavTrap::ScavTrap(const std::string& name)

{
	std::cout << "Name constructor called [ScavTrap]" << std::endl;
	this->name = name;
	this->hit_point = default_hit_point;
	this->energy_point = default_energy_point;
	this->attack_damage = default_attack_damage;
}

ScavTrap::ScavTrap(const ScavTrap &instance)
{
	std::cout << "Copy constructor called [ScavTrap]" << std::endl;
	*this = instance;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rvalue)
{
	std::cout << "Assignment operator called [ScavTrap]" << std::endl;
	if (this == &rvalue)
		return (*this);
	this->name = rvalue.name;
	this->hit_point = rvalue.hit_point;
	this->energy_point = rvalue.energy_point;
	this->attack_damage = rvalue.attack_damage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << this->name << " destructor called [ScavTrap]" << std::endl;
}

bool	ScavTrap::hasEnoughPoint()
{
	if (hit_point < 1)
	{
		std::cout << "[ScavTrap] " \
			<< this->name << " dosen't have enough hit point" \
			<< std::endl;
		return false;
	}
	if (energy_point < 1)
	{
		std::cout << "[ScavTrap] " \
			<< this->name << " dosen't have enough energy point" \
			<< std::endl;
		return false;
	}
	return true;
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << "[ScavTrap] " \
		<< this->name << " tried to attack" \
		<< std::endl;
	if (!hasEnoughPoint())
		return ;
	energy_point -= 1;
	std::cout << "[ScavTrap] " \
		<< this->name << " attacks " \
		<< target << ", causing " \
		<< this->attack_damage << " points of damage!" \
		<< std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (!hasEnoughPoint())
		return ;
	std::cout << "[ScavTrap] " \
	<< this->name << " is now in Gate keeper mode" \
	<< std::endl;
}

void	ScavTrap::printStatus(void)
{
	const std::string RED = "\033[31m";
	const std::string GREEN = "\033[32m";
	const std::string RESET = "\033[0m";
	const std::string BLUE = "\033[34m";

	std::cout << "[ScavTrap] " << BLUE << this->name << RESET \
		<< " hp: " << RED << this->hit_point << RESET \
		<< " energy: " << GREEN << this->energy_point << RESET \
		<< " damage: " << this->attack_damage \
		<< std::endl;
}
