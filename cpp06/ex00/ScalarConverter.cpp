#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "[ScalarConverter]: " << "Default constrcutor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& instance)
{
	*this = instance;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "[ScalarConverter]: " << "Destructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rvalue)
{
	if (this == &rvalue)
		return (*this);
	return (*this);
}

char toChar(const std::string& target)
{
	if ()
	std::atoi();
}
int toInt(const std::string& target)
{
	std::atoi(target.c_str());
}
float toFloat(const std::string& target);
double toDouble(const std::string& target);
