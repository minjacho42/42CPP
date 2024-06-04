#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "[Cat]"
		<< ": Default constructor called"
		<< std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& instance): Animal(instance)
{
	std::cout << "[Cat]"
		<< ": Copy constructor called"
		<< std::endl;
	*this = instance;
}

Cat::~Cat()
{
	std::cout << "[Cat]"
		<< ": Desturctor called"
		<< std::endl;
	delete brain;
}

Cat& Cat::operator=(const Cat& rvalue)
{
	std::cout << "[CAT] assign operator" << std::endl;
	if (this == &rvalue)
		return (*this);
	this->type = rvalue.type;
	this->brain = rvalue.brain;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "[Cat]"
		<< ": MEAW MEOW MEH AEH"
		<< std::endl;
}

void	Cat::setBrain(Brain& brain)
{
	delete this->brain;
	this->brain = &brain;
}

const Brain&	Cat::getBrain(void) const
{
	return *this->brain;
}

void	Cat::printBrain(void) const
{
	this->brain->printIdeas();
}
