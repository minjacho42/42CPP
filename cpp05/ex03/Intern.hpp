#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		std::string forms[3];
		static const int form_len = 3;
	public:
		Intern();
		Intern(const Intern& intern);
		Intern& operator=(const Intern& rvalue);
		~Intern();

		AForm	*makeForm(const std::string form_name, const std::string target);
};

#endif
