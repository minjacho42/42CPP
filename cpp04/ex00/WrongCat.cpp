#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "[WrongCat]"
		<< ": Default constructor called"
		<< std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& instance): WrongAnimal(instance)
{
	std::cout << "[WrongCat]"
		<< ": Copy constructor called"
		<< std::endl;
	*this = instance;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat]"
		<< ": Desturctor called"
		<< std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rvalue)
{
	if (this == &rvalue)
		return (*this);
	this->type = rvalue.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "[WrongCat]"
		<< ": WRONG MEAW MEOW MEH AEH"
		<< std::endl;
}
