#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char *argv[])
{
	std::string	s;

	for (int i = 1; i < argc; i++)
	{
		s = argv[i];
		for (size_t idx = 0; idx < s.length(); idx++)
			s[idx] = isalpha(s[idx]) ? toupper(s[idx]) : s[idx];
		std::cout << s;
	}
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
}
