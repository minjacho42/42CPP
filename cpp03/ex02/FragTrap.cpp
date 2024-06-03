# include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Default constructor called [FragTrap]" << std::endl;
	this->hit_point = default_hit_point;
	this->energy_point = default_energy_point;
	this->attack_damage = default_attack_damage;
}

FragTrap::FragTrap(std::string name)

{
	std::cout << "Name constructor called [FragTrap]" << std::endl;
	this->name = name;
	this->hit_point = default_hit_point;
	this->energy_point = default_energy_point;
	this->attack_damage = default_attack_damage;
}

FragTrap::FragTrap(FragTrap &instance)
{
	std::cout << "Copy constructor called [FragTrap]" << std::endl;
	*this = instance;
}

FragTrap& FragTrap::operator=(const FragTrap& rvalue)
{
	std::cout << "Assignment operator called [FragTrap]" << std::endl;
	if (this == &rvalue)
		return (*this);
	this->name = rvalue.name;
	this->hit_point = rvalue.hit_point;
	this->energy_point = rvalue.energy_point;
	this->attack_damage = rvalue.attack_damage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << this->name << " destructor called [FragTrap]" << std::endl;
}

bool	FragTrap::hasEnoughPoint()
{
	if (hit_point < 1)
	{
		std::cout << "[FragTrap] " \
			<< this->name << " dosen't have enough hit point" \
			<< std::endl;
		return false;
	}
	if (energy_point < 1)
	{
		std::cout << "[FragTrap] " \
			<< this->name << " dosen't have enough energy point" \
			<< std::endl;
		return false;
	}
	return true;
}

void	FragTrap::attack(const std::string& target)
{
	std::cout << "[FragTrap] " \
		<< this->name << " tried to attack" \
		<< std::endl;
	if (!hasEnoughPoint())
		return ;
	energy_point -= 1;
	std::cout << "[FragTrap] " \
		<< this->name << " attacks " \
		<< target << ", causing " \
		<< this->attack_damage << " points of damage!" \
		<< std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "[FragTrap] " \
	<< this->name << ": HIGHFIVE!! GUYS!" \
	<< std::endl;
}

void	FragTrap::printStatus(void)
{
	const std::string RED = "\033[31m";
	const std::string GREEN = "\033[32m";
	const std::string RESET = "\033[0m";
	const std::string BLUE = "\033[34m";

	std::cout << "[FragTrap] " << BLUE << this->name << RESET \
		<< " hp: " << RED << this->hit_point << RESET \
		<< " energy: " << GREEN << this->energy_point << RESET \
		<< " damage: " << this->attack_damage \
		<< std::endl;
}
