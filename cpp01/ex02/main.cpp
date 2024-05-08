# include <string>
# include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string& stringREF = str;
	std::cout << "MEMORY ADDRESS OF THE STRING VARIABLE >> \033[1;31m"<< &str << "\033[0m << \n";
	std::cout << "MEMORY ADDRESS HELD BY stringPTR >> \033[1;31m"<< &stringPTR << "\033[0m << \n";
	std::cout << "MEMORY ADDRESS HELD BY stringREF >> \033[1;31m"<< &stringREF << "\033[0m << \n";
	std::cout << "THE VALUE OF THE STRING VARIABLE >> \033[1;31m"<< str << "\033[0m << \n";
	std::cout << "THE VALUE POINTED TO BY stringPTR >> \033[1;31m"<< stringPTR << "\033[0m << \n";
	std::cout << "THE VALUE POINTED TO BY stringREF >> \033[1;31m"<< stringREF << "\033[0m << \n";
}
