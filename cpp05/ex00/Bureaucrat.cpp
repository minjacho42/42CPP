#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name), grade(grade)
{
	std::cout << "[Bureaucrat]: Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& instance): name(instance.name)
{
	*this = instance;
}

// Bureaucrat's assign operator doesn't assign name field
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rvalue)
{
	if (this == &rvalue)
		return (*this);
	this->grade = rvalue.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat]: "<< this->name <<" destructed" << std::endl;
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::increaseGrade()
{

}

void Bureaucrat::decreaseGrade()
{

}
