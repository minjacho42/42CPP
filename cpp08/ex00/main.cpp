#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
	int arr[] = {1,2,3,4,5,6,7,8,9};
	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
	std::list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));

	std::vector<int>::iterator v_i;
	try {
		v_i = easyfind(v, 3);
		std::cout << *v_i << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::list<int>::iterator l_i;
	try {
		l_i = easyfind(l, 213);
		std::cout << *l_i << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
