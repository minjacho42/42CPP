#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
	std::string			input;
	std::string			leftover;
	std::stringstream	ss;

	if (argc != 2)
	{
		std::cout << "usage: ./convert <input>" << std::endl;
		return (1);
	}
	ss.str(argv[1]);
	ss >> input;
	if (!ss.eof())
	{
		ss >> leftover;
		if (leftover.length() > 0)
		{
			std::cout << "Invalid Input" << std::endl;
			return (1);
		}
	}
	LiteralCompound result = ScalarConverter::convert(input);
	std::cout << result << std::endl;
}
