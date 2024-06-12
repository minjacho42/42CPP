#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name), grade(grade)
{
	std::cout << "[Bureaucrat]: Constructor called" << std::endl;
	if (grade > lowest_grade)
		throw Bureaucrat::GradeTooLowException();
	if (grade < highest_grade)
		throw Bureaucrat::GradeTooHighException();
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
	if (this->grade <= highest_grade)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}

void Bureaucrat::decreaseGrade()
{
	if (this->grade >= lowest_grade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

void Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->name << " couldn’t sign " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rvalue)
{
	os << rvalue.getName() << ", bureaucrat grade " << rvalue.getGrade();
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	const char* reason = "Grade is too high for bureaucrat";
	return (reason);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	const char* reason = "Grade is too low for bureaucrat";
	return (reason);
}
