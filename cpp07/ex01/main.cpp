# include "iter.hpp"
# include <iostream>

template <typename T>
void print(T& t)
{
	std::cout << t << std::endl;
}

template <typename T>
void printc(const T& t)
{
	std::cout << t << std::endl;
}

int main()
{
	std::string arr[4] = {"a", "b", "c", "d"};
	const std::string arr2[4] = {"1","2","3","4"};
	int iarr[4] = {1, 2, 3, 4};
	const int iarr2[4] = {1, 2, 3, 4};

	iter(arr, 4, print);
	iter(arr2, 4, printc);
	iter(iarr, 4, printc);
	iter(iarr2, 4, print);
}
