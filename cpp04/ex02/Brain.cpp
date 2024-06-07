#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain]: Default constructor called" << std::endl;
}

Brain::Brain(const Brain& instance)
{
	std::cout << "[Brain]: Copy constructor called" << std::endl;
	*this = instance;
}

Brain::~Brain()
{
	std::cout << "[Brain]: Desctructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& rvalue)
{
	std::cout << "[Brain]: assign operator called" << std::endl;
	if (this == &rvalue)
		return *this;
	for (int i = 0; i < ideas_length; i++)
		this->ideas[i] = rvalue.ideas[i];
	return *this;
}

// allocate new array of string and return
const std::string	*Brain::getIdeas(void) const
{
	return (this->ideas);
}

void	Brain::setIdeas(const std::string *ideas)
{
	for (int i = 0; i < ideas_length; i++)
		this->ideas[i] = ideas[i];
}

void	Brain::printIdeas(void) const
{
	for (int i = 0; i < ideas_length; i++)
	{
		if (this->ideas[i].length())
			std::cout << "[" << i << "]: " << this->ideas[i] << std::endl;
	}
}
