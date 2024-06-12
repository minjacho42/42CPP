#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			grade_to_sign;
		const int			grade_to_excute;
		static const int	lowest_grade = 150;
		static const int	highest_grade = 1;
		AForm();
	public:
		AForm(const std::string& name, const int grade_to_sign, const int grade_to_excute);
		AForm(const AForm& instance);
		AForm& operator=(const AForm& rvalue);
		virtual ~AForm();

		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExcute() const;

		void	beSigned(const Bureaucrat& bureaucrat);

		virtual void	execute(const Bureaucrat& executer) const = 0;

		class GradeTooHighException: public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class AlreadySignedFormException: public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class NotSignedFormException: public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& rvalue);

#endif
