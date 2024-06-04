#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
	std::cout << "[WrongAnimal]"
		<< ": Default constructor called"
		<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& instance)
{
	std::cout << "[WrongAnimal]"
		<< ": Copy constructor called"
		<< std::endl;
	*this = instance;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal]"
		<< ": Desturctor called"
		<< std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rvalue)
{
	if (this == &rvalue)
		return (*this);
	this->type = rvalue.type;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "[WrongAnimal]"
		<< ": I'M WRONGANIMAL!!!"
		<< std::endl;
}
