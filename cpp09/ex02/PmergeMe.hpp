#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <utility>
# include <vector>
# include <deque>
# include <cmath>
# include <exception>

class PmergeMe {
	private:
		int k;
		int n;
		int level;
		std::vector<int> pair_v;
		std::deque<int> pair_d;
		std::vector< std::pair<int, int> > v;
		std::deque< std::pair<int, int> > d;

		PmergeMe();
		void initPairV();
		void initPairD();

	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe& instance);
		PmergeMe& operator=(const PmergeMe& rvalue);

		void runVector();
		void runDeque();
		std::vector<int> getSortedVec();
		std::deque<int> getSortedDeque();
};

#endif
