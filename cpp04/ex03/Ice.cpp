#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "[ICE]: "
		<< "default constructor called"
		<< std::endl;
}

Ice::Ice(const Ice& instance): AMateria(instance)
{
	*this = instance;
}

Ice& Ice::operator=(const Ice& rvalue)
{
	if (this == &rvalue)
		return (*this);
	return (*this);
}

Ice::~Ice()
{
	std::cout << "[ICE]: "
		<< "destructor called"
		<< std::endl;
}

AMateria* Ice::clone() const
{
	AMateria*	new_materia;

	new_materia = new Ice();
	return new_materia;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName()
		<< " *" << std::endl;
}
