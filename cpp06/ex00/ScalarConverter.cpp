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

int ScalarConverter::getLiteralType(const std::string& target)
{
	std::stringstream	ss1;
	std::stringstream	ss2;
	double				value_d;
	int					value_i;
	float				value_f;

	// std::cout << "target : " << target << std::endl;
	if (target.length() < 1)
		return (NONE);
	if (target.compare("nan") == 0 || target.compare("-nan") == 0 || target.compare("inf") == 0 || target.compare("-inf") == 0)
		return (DOUBLE);
	if (target.compare("nanf") == 0 || target.compare("-nanf") == 0 || target.compare("inff") == 0 || target.compare("-inff") == 0)
		return (FLOAT);
	if (target.length() == 1 && !isdigit(target[0]))
		return (CHAR);
	ss1.str(target);
	ss1 >> value_i;
	if (ss1.eof())
		return (INT);
	if (target[target.length() - 1] == 'f')
	{
		// std::cout << target.substr(0, target.length() - 1) << std::endl;
		ss2.str(target.substr(0, target.length() - 1));
		ss2 >> value_f;
		if (ss2.eof() && !ss2.fail())
			return (FLOAT);
		else
			return (NONE);
	}
	else
		ss2.str(target);
	ss2 >> value_d;
	if (ss2.eof() && !ss2.fail())
		return (DOUBLE);
	return (NONE);
}

LiteralCompound ScalarConverter::convert(const std::string& target)
{
	std::stringstream	ss;
	char				value_c;
	double				value_d;
	int					value_i;
	float				value_f;
	int					literal_type;

	literal_type = getLiteralType(target);
	// std::cout << literal_type << std::endl;
	switch (literal_type)
	{
		case INT:
			ss.str(target);
			ss >> value_i;
			return (LiteralCompound(value_i, ss.fail()));
		case CHAR:
			ss.str(target);
			ss >> value_c;
			return (LiteralCompound(value_c));
		case FLOAT:
			ss.str(target.substr(0, target.length() - 1));
			ss >> value_f;
			return (LiteralCompound(value_f, target));
		case DOUBLE:
			ss.str(target);
			ss >> value_d;
			return (LiteralCompound(value_d, target));
		case NONE:
			break;
	}
	return (LiteralCompound());
}
