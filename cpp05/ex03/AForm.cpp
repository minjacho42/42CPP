#include "AForm.hpp"

AForm::AForm(const std::string& name, const int grade_to_sign, const int grade_to_excute):
	name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_excute(grade_to_excute)
{}

AForm::AForm(const AForm& instance):
	name(instance.name), is_signed(instance.is_signed), grade_to_sign(instance.grade_to_sign), grade_to_excute(instance.grade_to_excute)
{}

// assign operator couldn't assgin name, grade_to_sign, grade_to_excute
AForm& AForm::operator=(const AForm& rvalue)
{
	if (this == &rvalue)
		return (*this);
	is_signed = rvalue.is_signed;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "[AForm]: " << name << " destructed" << std::endl;
}

const std::string AForm::getName() const
{
	return (name);
}

bool AForm::getIsSigned() const
{
	return (is_signed);
}

int AForm::getGradeToSign() const
{
	return (grade_to_sign);
}

int AForm::getGradeToExcute() const
{
	return (grade_to_excute);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= grade_to_sign)
	{
		if (is_signed)
			throw AForm::AlreadySignedFormException();
		is_signed = true;
	}
	else
		throw AForm::GradeTooLowException();
}
std::ostream& operator<<(std::ostream& os, const AForm& rvalue)
{
	const std::string is_signed_str = rvalue.getIsSigned() ? "true" : "false";
	os 	<< "===== AForm ["<< rvalue.getName() << "]=====\n"
		<< "Signed: " << is_signed_str << "\n"
		<< "Grade to sign: " << rvalue.getGradeToSign() << "\n"
		<< "Grade to excute: " << rvalue.getGradeToExcute()
		<< "\n====================";
	return os;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	const char* reason = "Grade is too high for form";
	return (reason);
}

const char* AForm::GradeTooLowException::what() const throw()
{
	const char* reason = "Grade is too low for form";
	return (reason);
}

const char* AForm::AlreadySignedFormException::what() const throw()
{
	const char* reason = "AForm is already signed";
	return (reason);
}

const char* AForm::NotSignedFormException::what() const throw()
{
	const char* reason = "AForm wasn't signed yet";
	return (reason);
}
