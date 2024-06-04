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
	if (this == &rvalue)
		return *this;
	for (int i = 0; i < ideas_length; i++)
		this->ideas[i] = rvalue.ideas[i];
	return *this;
}

// allocate new array of string and return
std::string	*Brain::getIdeas(void) const
{
	std::string *result = new std::string[ideas_length];
	for (int i = 0; i < ideas_length; i++)
		result[i] = this->ideas[i];
	return (result);
}

void	Brain::setIdeas(const std::string *ideas)
{

}
