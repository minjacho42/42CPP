#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	target;
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& instance);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rvalue);
		virtual ~ShrubberyCreationForm();

		virtual void	execute(const Bureaucrat& executer) const;
		class FileCantOpenException: public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

#endif
