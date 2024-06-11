#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
		static const int	lowest_grade = 150;
		static const int	highest_grade = 1;
		Bureaucrat();
	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& instance);
		virtual ~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& rvalue);

		const std::string	getName() const;
		int					getGrade() const;

		void				increaseGrade();
		void				decreaseGrade();
		void				signForm(AForm& form) const;
		void				executeForm(const AForm& form) const;

		class GradeTooHighException : public std::exception{};
		class GradeTooLowException : public std::exception{};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rvalue);

#endif