#include "Form.hpp"

Form::Form(const std::string& name, const int grade_to_sign, const int grade_to_excute):
	name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_excute(grade_to_excute)
{
	if (grade_to_excute < highest_grade || grade_to_sign < highest_grade)
		throw Form::GradeTooHighException();
	if (grade_to_excute > lowest_grade || grade_to_sign > lowest_grade)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& instance):
	name(instance.name), is_signed(instance.is_signed), grade_to_sign(instance.grade_to_sign), grade_to_excute(instance.grade_to_excute)
{}

// assign operator couldn't assgin name, grade_to_sign, grade_to_excute
Form& Form::operator=(const Form& rvalue)
{
	if (this == &rvalue)
		return (*this);
	is_signed = rvalue.is_signed;
	return (*this);
}

Form::~Form()
{
	std::cout << "[Form]: " << name << " destructed" << std::endl;
}

const std::string Form::getName() const
{
	return (name);
}

bool Form::getIsSigned() const
{
	return (is_signed);
}

int Form::getGradeToSign() const
{
	return (grade_to_sign);
}

int Form::getGradeToExcute() const
{
	return (grade_to_excute);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= grade_to_sign)
	{
		if (is_signed)
			throw Form::AlreadySignedFormException();
		is_signed = true;
	}
	else
		throw Form::GradeTooLowException();
}
std::ostream& operator<<(std::ostream& os, const Form& rvalue)
{
	const std::string is_signed_str = rvalue.getIsSigned() ? "true" : "false";
	os 	<< "===== Form ["<< rvalue.getName() << "]=====\n"
		<< "Signed: " << is_signed_str << "\n"
		<< "Grade to sign: " << rvalue.getGradeToSign() << "\n"
		<< "Grade to excute: " << rvalue.getGradeToExcute()
		<< "\n====================";
	return os;
}

const char* Form::GradeTooHighException::what() const throw()
{
	const char* reason = "Grade is too high for form";
	return (reason);
}

const char* Form::GradeTooLowException::what() const throw()
{
	const char* reason = "Grade is too low for form";
	return (reason);
}

const char* Form::AlreadySignedFormException::what() const throw()
{
	const char* reason = "Form is already signed";
	return (reason);
}
