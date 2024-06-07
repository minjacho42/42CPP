#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "[Cure]: "
		<< "default constructor called"
		<< std::endl;
}

Cure::Cure(const Cure& instance): AMateria(instance)
{
	*this = instance;
}

Cure& Cure::operator=(const Cure& rvalue)
{
	if (this == &rvalue)
		return (*this);
	this->type = rvalue.type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "[Cure]: "
		<< "destructor called"
		<< std::endl;
}

AMateria* Cure::clone() const
{
	AMateria*	new_materia;

	new_materia = new Cure();
	return new_materia;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName()
		<< "'s wounds *" << std::endl;
}
