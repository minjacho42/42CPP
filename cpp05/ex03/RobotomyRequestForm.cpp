#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	AForm("RobotomyRequestForm", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& instance):
	AForm(instance), target(instance.target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rvalue)
{
	if (this == &rvalue)
		return (*this);
	target = rvalue.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm]: destructed" << std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executer) const
{
	const std::string RED = "\033[0;31m";
	const std::string GREEN = "\033[0;32m";
	const std::string BLUE = "\033[0;34m";
	const std::string RESET = "\033[0m";

	if (!this->getIsSigned())
		throw AForm::NotSignedFormException();
	if (this->getGradeToExcute() < executer.getGrade())
		throw AForm::GradeTooLowException();

	std::cout << BLUE << "Vroom... vroom...\nBrrrr... brrrr...\nWhirr... whirr..." << RESET << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2 == 0)
		std::cout << GREEN << target << " successfully robotomized" << RESET << std::endl;
	else
		std::cout << RED << target << " robomize failed" << RESET << std::endl;
}
