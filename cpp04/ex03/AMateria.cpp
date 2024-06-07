#include "AMateria.hpp"

AMateria::AMateria(const std::string& type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria& instance)
{
	*this = instance;
}

AMateria& AMateria::operator=(const AMateria& rvalue)
{
	if (this == &rvalue)
		return (*this);

	this->type = rvalue.type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "[AMateria]: "
		<< type << " destructor called"
		<< std::endl;
}

const std::string& AMateria::getType() const
{
	return this->type;
}

