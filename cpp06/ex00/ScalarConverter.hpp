#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <cctype>
# include <cstdlib>
# include <sstream>
# include "LiteralCompound.hpp"

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3
# define NONE 4

class LiteralCompound;

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& instance);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& rvalue);
		static int	getLiteralType(const std::string& target);
	public:
		static LiteralCompound	convert(const std::string& target);
};

#endif
