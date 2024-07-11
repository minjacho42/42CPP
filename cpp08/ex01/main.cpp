#include "Span.hpp"
#include <iostream>

int main() {
	Span sp = Span(20);
	int arr[] = {1,2,3,4,5,6,7,8,9};
	std::list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));

	sp.addNumber(6);
	sp.addNumber(2);
	sp.addNumber(3);
	sp.addNumber(10);
	sp.addNumber(12);
	sp.addNumber< std::list<int> >(l.begin(), l.end());

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
