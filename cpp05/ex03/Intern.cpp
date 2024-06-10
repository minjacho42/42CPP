#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor" << std::endl;
	forms[0] = "shrubbery creation";
	forms[1] = "robotomy request";
	forms[2] = "presidential pardon";
}

Intern::Intern(const Intern& intern)
{
	std::cout << "Intern Copy Constructor" << std::endl;
	*this = intern;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor" << std::endl;
}

Intern& Intern::operator=(const Intern& rvalue)
{
	if (this == &rvalue)
		return (*this);
	for (int i = 0; i < form_len; i++)
		forms[i] = rvalue.forms[i];
	return (*this);
}

AForm	*Intern::makeForm(const std::string form_name, const std::string target)
{
	int	i;
	AForm *new_form;

	for (i = 0; i < form_len; i++)
		if (forms[i].compare(form_name) == 0)
			break;
	switch (i)
	{
		case 0:
			new_form = new ShrubberyCreationForm(target);
			break;
		case 1:
			new_form = new RobotomyRequestForm(target);
			break;
		case 2:
			new_form = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "No such form name" << std::endl;
			new_form = NULL;
	}
	return new_form;
}


