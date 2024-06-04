#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "[Dog]"
		<< ": Default constructor called"
		<< std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& instance): Animal(instance)
{
	std::cout << "[Dog]"
		<< ": Copy constructor called"
		<< std::endl;
	*this = instance;
	brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "[Dog]"
		<< ": Desturctor called"
		<< std::endl;
	delete brain;
}

Dog& Dog::operator=(const Dog& rvalue)
{
	std::cout << "[DOG] assign operator" << std::endl;
	if (this == &rvalue)
		return (*this);
	this->type = rvalue.type;
	this->brain = rvalue.brain;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "[Dog]"
		<< ": BOW WOW BOW WOW BOW WOW"
		<< std::endl;
}
