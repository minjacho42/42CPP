#include "AAnimal.hpp"

AAnimal::AAnimal(): type("AAnimal")
{
	std::cout << "[AAnimal]"
		<< ": Default constructor called"
		<< std::endl;
}

AAnimal::AAnimal(const AAnimal& instance)
{
	std::cout << "[AAnimal]"
		<< ": Copy constructor called"
		<< std::endl;
	*this = instance;
}

AAnimal::~AAnimal()
{
	std::cout << "[AAnimal]"
		<< ": Desturctor called"
		<< std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& rvalue)
{
	if (this == &rvalue)
		return (*this);
	this->type = rvalue.type;
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return (this->type);
}
