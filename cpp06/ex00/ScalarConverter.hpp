#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>

class ScalarConverter
{

	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& instance);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& rvalue);

		static char		toChar(const std::string& target);
		static int		toInt(const std::string& target);
		static float	toFloat(const std::string& target);
		static double	toDouble(const std::string& target);
};

#endif
