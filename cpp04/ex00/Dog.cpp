#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "[Dog]"
		<< ": Default constructor called"
		<< std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& instance): Animal(instance)
{
	std::cout << "[Dog]"
		<< ": Copy constructor called"
		<< std::endl;
	*this = instance;
}

Dog::~Dog()
{
	std::cout << "[Dog]"
		<< ": Desturctor called"
		<< std::endl;
}

Dog& Dog::operator=(const Dog& rvalue)
{
	if (this == &rvalue)
		return (*this);
	this->type = rvalue.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "[Dog]"
		<< ": BOW WOW BOW WOW BOW WOW"
		<< std::endl;
}
