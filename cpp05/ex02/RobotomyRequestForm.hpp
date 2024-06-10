#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <ctime>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm
{
	private:
		std::string	target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& instance);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& rvalue);
		virtual ~RobotomyRequestForm();

		virtual void	execute(const Bureaucrat& executer) const;
};

#endif
