#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
	AForm("PresidentialPardonForm", 25, 5), target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& instance):
	AForm(instance), target(instance.target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rvalue)
{
	if (this == &rvalue)
		return (*this);
	target = rvalue.target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm]: destructed" << std::endl;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executer) const
{
	const std::string RED = "\033[0;31m";
	const std::string RESET = "\033[0m";

	if (!this->getIsSigned())
		throw AForm::NotSignedFormException();
	if (this->getGradeToExcute() < executer.getGrade())
		throw AForm::GradeTooLowException();

	std::cout << RED << target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}
