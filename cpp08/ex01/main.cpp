#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


int main() {
	Span sp = Span(100);
	int arr[] = {10,2,100,42,55,6,723,8,91};
	std::list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));

	std::srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < 10; i++) {
		int num = rand() % 100000;
		std::cout << num << std::endl;
		try {
			sp.addNumber(num);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	sp.printer();
	// sp.addNumber< std::list<int> >(l.begin(), l.end());
	// sp.printer();
	try {
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
