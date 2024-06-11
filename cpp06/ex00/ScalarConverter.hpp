#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>

class ScalarConverter
{
	private:
		static std::string	trimSpace(std::string& target);

	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& instance);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& rvalue);

		static bool		isChar(const std::string& target);
		static bool		isInt(const std::string& target);
		static bool		isFloat(const std::string& target);
		static bool		isDouble(const std::string& target);
		static char		toChar(const std::string& target);
		static int		toInt(const std::string& target);
		static float	toFloat(const std::string& target);
		static double	toDouble(const std::string& target);
};

#endif
