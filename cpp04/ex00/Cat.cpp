#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "[Cat]"
		<< ": Default constructor called"
		<< std::endl;
	type = "Cat";
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
}

Cat& Cat::operator=(const Cat& rvalue)
{
	if (this == &rvalue)
		return (*this);
	this->type = rvalue.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "[Cat]"
		<< ": MEAW MEOW MEH AEH"
		<< std::endl;
}
