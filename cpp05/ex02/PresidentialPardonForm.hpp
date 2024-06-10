#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm
{
	private:
		std::string	target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& instance);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& rvalue);
		virtual ~PresidentialPardonForm();

		virtual void	execute(const Bureaucrat& executer) const;
};

#endif
