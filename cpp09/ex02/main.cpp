#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

int main(int argc, char *argv[]) {
	PmergeMe sort = PmergeMe(argc, argv);
	PmergeMe vecSort = PmergeMe(argc, argv);
	PmergeMe listSort = PmergeMe(argc, argv);
	std::cout << "Before:";
	for (int i = 1; i < argc; i++) {
		std::cout << " " << argv[i];
	}
	std::cout << std::endl;
	sort.runVector();
	std::vector<int> sorted_vec = sort.getSortedVec();
	std::cout << "After:";
	for (std::vector<int>::iterator it = sorted_vec.begin(); it != sorted_vec.end(); it++) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
	std::clock_t start_vec = std::clock();
	vecSort.runVector();
	std::clock_t end_vec = std::clock();
    double vec_time = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;
    double vec_time_microsec = vec_time * 1e6;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << vec_time_microsec << " us" << std::endl;
	std::clock_t start_list = std::clock();
	listSort.runList();
	std::clock_t end_list = std::clock();
    double list_time = static_cast<double>(end_list - start_list) / CLOCKS_PER_SEC;
    double list_time_microsec = list_time * 1e6;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::list : " << list_time_microsec << " us" << std::endl;
}
