#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <utility>
# include <vector>
# include <list>
# include <cmath>
# include <exception>

class PmergeMe {
	private:
		int k;
		int n;
		int level;
		std::vector<int> pair;
		std::list<int> pair_l;
		std::vector< std::pair<int, int> > v;
		std::list< std::pair<int, int> > l;

		PmergeMe();
		void initPair();

	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe& instance);
		PmergeMe& operator=(const PmergeMe& rvalue);

		void runVector();
		void runList();
		std::vector<int> getSortedVec();
		std::list<int> getSortedList();
};

#endif
