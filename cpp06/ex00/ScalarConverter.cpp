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

std::string ScalarConverter::trimSpace(std::string& target)
{
	int i = 0;
	int j = target.length() - 1;

	while (i < j + 1 && (target[i] == ' ' || target[i] == '\t'))
		i++;
	while (i < j + 1 && (target[j] == ' ' || target[j] == '\t'))
		j--;
	return (target.substr(i, j - i + 1));
}

bool ScalarConverter::isChar(const std::string& target)
{
	if (!(target.length() == 3 && target[0] == '\'' && target[2] == '\''))
		return false;
	if (isprint(target[1]))
		return true;
	else
		return false;
}

// char toChar(const std::string& target)
// {
// 	if ()
// 	std::atoi();
// }
int toInt(const std::string& target)
{
	std::atoi(target.c_str());
}
float toFloat(const std::string& target);
double toDouble(const std::string& target);
