#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
	if (argc != 2)
		return (1);
	std::string str(argv[1]);
	RPN rpn = RPN(str);
	try {
		std::cout << rpn.run() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
