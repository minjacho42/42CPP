#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
		static const int	lowest_grade = 150;
		static const int	highest_grade = 1;
		Bureaucrat();
		void gradeChecker();
	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& instance);
		virtual ~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& rvalue);
		const std::string	getName() const;
		int					getGrade() const;
		void				increaseGrade();
		void				decreaseGrade();
};

#endif
