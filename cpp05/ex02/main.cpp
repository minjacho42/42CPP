#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat	minjacho145 = Bureaucrat("minjacho145", 145);
	Bureaucrat	minjacho72 = Bureaucrat("minjacho72", 72);
	Bureaucrat	minjacho23 = Bureaucrat("minjacho23", 23);
	Bureaucrat	boss = Bureaucrat("Boss", 3);
	AForm		*shrubbery = new ShrubberyCreationForm("test");
	AForm		*robotomy = new RobotomyRequestForm("robotomy");
	AForm		*presidential = new PresidentialPardonForm("test");

	std::cout << minjacho145 << "\n" << boss << std::endl;
	std::cout << *shrubbery << std::endl;
	minjacho145.signForm(*shrubbery);
	minjacho145.executeForm(*shrubbery);
	boss.executeForm(*shrubbery);
	std::cout << *shrubbery << std::endl;
	delete shrubbery;

	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << *robotomy << std::endl;
	minjacho72.signForm(*robotomy);
	minjacho72.executeForm(*robotomy);
	boss.executeForm(*robotomy);
	std::cout << *robotomy << std::endl;
	delete robotomy;

	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << *presidential << std::endl;
	minjacho23.signForm(*presidential);
	minjacho23.executeForm(*presidential);
	boss.executeForm(*presidential);
	std::cout << *presidential << std::endl;
	delete presidential;
}
