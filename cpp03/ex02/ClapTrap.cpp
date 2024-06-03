# include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("anonymous"),
hit_point(default_hit_point),
energy_point(default_energy_point),
attack_damage(default_attack_damage)
{
	std::cout << "Default constructor called [ClapTrap]" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): name(name),
hit_point(default_hit_point),
energy_point(default_energy_point),
attack_damage(default_attack_damage)
{
	std::cout << "Name constructor called [ClapTrap]" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &instance)
{
		std::cout << "Copy constructor called [ClapTrap]" << std::endl;
	*this = instance;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rvalue)
{
	std::cout << "Assignment operator called [ClapTrap]" << std::endl;
	if (this == &rvalue)
		return (*this);
	this->name = rvalue.name;
	this->hit_point = rvalue.hit_point;
	this->energy_point = rvalue.energy_point;
	this->attack_damage = rvalue.attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << this->name << " destructor called [ClapTrap]" << std::endl;
}

bool	ClapTrap::hasEnoughPoint()
{
	if (hit_point < 1)
	{
		std::cout << "[ClapTrap] " \
			<< this->name << " dosen't have enough hit point" \
			<< std::endl;
		return false;
	}
	if (energy_point < 1)
	{
		std::cout << "[ClapTrap] " \
			<< this->name << " dosen't have enough energy point" \
			<< std::endl;
		return false;
	}
	return true;
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << "[ClapTrap] " \
		<< this->name << " tried to attack" \
		<< std::endl;
	if (!hasEnoughPoint())
		return ;
	energy_point -= 1;
	std::cout << "[ClapTrap] " \
		<< this->name << " attacks " \
		<< target << ", causing " \
		<< this->attack_damage << " points of damage!" \
		<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int damage = this->hit_point < amount ? this->hit_point : amount;

	std::cout << "[ClapTrap] " \
		<< this->name << " has taken " \
		<< amount << " damage"
		<< std::endl;
	this->hit_point -= damage;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "[ClapTrap] " \
		<< this->name << " tried to be repaired" \
		<< std::endl;
	if (!hasEnoughPoint())
		return ;
	std::cout << "[ClapTrap] " \
		<< this->name << " is repaired " \
		<< amount << " hit point"
		<< std::endl;
	this->hit_point += amount;
	this->energy_point -= 1;
}

std::string	ClapTrap::getName(void)
{
	return (this->name);
}

unsigned int	ClapTrap::getHitPoint(void)
{
	return (this->hit_point);
}

unsigned int	ClapTrap::getEnergyPoint(void)
{
	return (this->energy_point);
}

unsigned int	ClapTrap::getAttackDamage(void)
{
	return (this->attack_damage);
}

void	ClapTrap::printStatus(void)
{
	const std::string RED = "\033[31m";
	const std::string GREEN = "\033[32m";
	const std::string RESET = "\033[0m";
	const std::string BLUE = "\033[34m";

	std::cout << "[ClapTrap] " << BLUE << this->name << RESET \
		<< " hp: " << RED << this->hit_point << RESET \
		<< " energy: " << GREEN << this->energy_point << RESET \
		<< " damage: " << this->attack_damage \
		<< std::endl;
}
