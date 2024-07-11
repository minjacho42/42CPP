#include "MutantStack.hpp"
#include <iostream>
#include <deque>
#include <list>
#include <vector>

int main() {
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	mstack.push(6);
	mstack.push(7);
	mstack.push(8);

	const MutantStack<int> c_mstack = mstack;

	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++) {
		std::cout << *it << std::endl;
		*it += 1;
	}

	for (MutantStack<int>::const_iterator cit = c_mstack.begin(); cit != c_mstack.end(); cit++) {
		std::cout << *cit << std::endl;
	}

	const std::stack<int> s(mstack);
}
