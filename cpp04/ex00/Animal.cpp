#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
	std::cout << "[Animal]"
		<< ": Default constructor called"
		<< std::endl;
}

Animal::Animal(const Animal& instance)
{
	std::cout << "[Animal]"
		<< ": Copy constructor called"
		<< std::endl;
	*this = instance;
}

Animal::~Animal()
{
	std::cout << "[Animal]"
		<< ": Desturctor called"
		<< std::endl;
}

Animal& Animal::operator=(const Animal& rvalue)
{
	if (this == &rvalue)
		return (*this);
	this->type = rvalue.type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "[Animal]"
		<< ": I'M ANIMAL!!!"
		<< std::endl;
}
