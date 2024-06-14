# include "whatever.hpp"
# include <iostream>

int main()
{
	int a = 10;
	int b = 4;

	::swap(a,b);
	std::cout << a << " " << b << std::endl;

	std::string str_a = "minjacho";
	std::string str_b = "choi minjae";
	::swap(str_a, str_b);
	std::cout << str_a << "\n" << str_b << std::endl;

	std::cout << ::max(a,b) << std::endl;
	std::cout << ::max(str_a,str_b) << std::endl;
	std::cout << ::min(a,b) << std::endl;
	std::cout << ::min(str_a,str_b) << std::endl;

	const std::string c_str_a = "hello";
	const std::string c_str_b = "world";

	std::cout << ::max(c_str_a,c_str_b) << std::endl;
	std::cout << ::min(c_str_a,c_str_b) << std::endl;
}
