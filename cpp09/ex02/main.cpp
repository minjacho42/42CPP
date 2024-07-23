#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Error: few arguments" << std::endl;
		return 1;
	}
	try {
		PmergeMe sort = PmergeMe(argc, argv);
		PmergeMe vecSort = PmergeMe(argc, argv);
		PmergeMe dequeSort = PmergeMe(argc, argv);
		std::cout << "Before:";
		for (int i = 1; i < argc; i++) {
			std::cout << " " << argv[i];
		}
		std::cout << std::endl;
		// sort.runVector();
		sort.runDeque();
		std::cout << "After:";
		// std::vector<int> sorted_vec = sort.getSortedVec();
		// for (std::vector<int>::iterator it = sorted_vec.begin(); it != sorted_vec.end(); it++) {
		// 	std::cout << " " << *it;
		// }
		std::deque<int> sorted_deque = sort.getSortedDeque();
		for (std::deque<int>::iterator it = sorted_deque.begin(); it != sorted_deque.end(); it++) {
			std::cout << " " << *it;
		}
		std::cout << std::endl;
		std::clock_t start_vec = std::clock();
		vecSort.runVector();
		std::clock_t end_vec = std::clock();
		double vec_time = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;
		double vec_time_microsec = vec_time * 1e6;
		std::cout << "Time to process a range of " << sorted_deque.size() << " elements with std::vector : " << vec_time_microsec << " us" << std::endl;
		std::clock_t start_deque = std::clock();
		dequeSort.runDeque();
		std::clock_t end_deque = std::clock();
		double deque_time = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC;
		double deque_time_microsec = deque_time * 1e6;
		std::cout << "Time to process a range of " << sorted_deque.size() << " elements with std::deque : " << deque_time_microsec << " us" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
