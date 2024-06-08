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
	*this->brain = *rvalue.brain;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "[Dog]"
		<< ": BOW WOW BOW WOW BOW WOW"
		<< std::endl;
}

void	Dog::setBrain(Brain& brain)
{
	*this->brain = brain;
}

const Brain&	Dog::getBrain(void) const
{
	return *this->brain;
}

void	Dog::printBrain(void) const
{
	this->brain->printIdeas();
}
