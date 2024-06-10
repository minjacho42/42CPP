#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			grade_to_sign;
		const int			grade_to_excute;
		Form();
	public:
		Form(const std::string& name, const int grade_to_sign, const int grade_to_excute);
		Form(const Form& instance);
		Form& operator=(const Form& rvalue);
		~Form();

		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExcute() const;

		void	beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class AlreadySignedFormException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& rvalue);

#endif
