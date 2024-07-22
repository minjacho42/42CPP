#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(int ac, char **av) {
	n = ac - 1;
	level = std::ceil(std::log2(n));
	k = std::pow(2, level);
	for (int i = 0; i < k; i++) {
		int num = i < n ? std::atoi(av[i + 1]) : -1;
		if (i < n && num < 0) {
			throw std::invalid_argument("argument is not a postivie number");
		}
		pair.push_back(num);
	}
}

PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe& instance) {
	*this = instance;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rvalue) {
	if (this != &rvalue) {
		this->pair = rvalue.pair;
	}
	return *this;
}

std::list<int>::iterator listAt(std::list<int> l, int idx){
	std::list<int>::iterator it = l.begin();
	for (int i = 0; i < idx; i++)
		it++;
	return it;
}

void PmergeMe::initPair() {
	for (int lv = 0; lv < level; lv++) {
		int step = std::pow(2, lv);
		for (int i = 0; i < k; i += step) {
			if (pair[i] < pair[i + step / 2]) {
				for (int j = i; j < i + step / 2; j++)
					std::swap(pair[j], pair[j + step / 2]);
			}
		}
	}
}

bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	return a.first < b.first;
}

void PmergeMe::runVector() {
	initPair();
	v.push_back(std::make_pair(pair[0], 0));
	for (int lv = level - 1; lv > -1; lv--) {
		// std::cout << "------\nlevel : " << lv << std::endl;
		std::vector< std::pair<int, int> > single_tmp;
		std::vector< std::pair<int, int> > tmp_v;
		for (std::vector< std::pair<int, int> >::iterator it = v.begin(); it != v.end(); it++) {
			int pair_idx = it->second + std::pow(2, lv);
			if (pair[pair_idx] < 0)
				single_tmp.push_back(*it);
			else
				tmp_v.push_back(*it);
		}
		// std::cout << "single size : " << single_tmp.size() << std::endl;
		int start_idx = 0;
		// std::cout << "size : " << tmp_v.size() << std::endl;
		int jacob = 0;
		while (start_idx < static_cast<int>(tmp_v.size())) {
			for (int i = start_idx + jacob; i >= start_idx; i--) {
				int pair_idx = tmp_v[i].second + std::pow(2, lv);
				if (pair[pair_idx] < 0) {
					continue;
				}
				std::pair<int, int> new_pair = std::make_pair(pair[pair_idx], pair_idx);
				v.insert(std::lower_bound(v.begin(), v.end(), new_pair, comparePairs), new_pair);
			}
			start_idx += (jacob + 1);
			int size_before = start_idx * 2 + 1;
			jacob = std::pow(2, std::floor(std::log2(size_before)) + 1) - size_before - 1;
			if (jacob < 0)
				jacob = 0;
			// std::cout << start_idx << " " << size_before << " " << jacob + 1 << std::endl;
			if (jacob > static_cast<int>(tmp_v.size()) - start_idx - 1)
				jacob = static_cast<int>(tmp_v.size()) - start_idx - 1;
		}
		for (std::vector< std::pair<int, int> >::iterator it = single_tmp.begin(); it != single_tmp.end(); it++) {
			std::pair<int, int> new_pair = *it;
			v.insert(std::lower_bound(v.begin(), v.end(), new_pair, comparePairs), new_pair);
		}
	}
}

void PmergeMe::runList() {
	initPair();
	l.push_back(std::make_pair(pair[0], 0));
	for (int lv = level - 1; lv > -1; lv--) {
		std::list< std::pair<int, int> > tmp_l = l;
		for (std::list< std::pair<int, int> >::iterator it = tmp_l.begin(); it != tmp_l.end(); it++) {
			int pair_idx = it->second + std::pow(2, lv);
			if (pair[pair_idx] < 0)
				continue;
			std::pair<int, int> new_pair = std::make_pair(pair[pair_idx], pair_idx);
			l.insert(std::lower_bound(l.begin(), l.end(), new_pair, comparePairs), new_pair);
		}
	}
}


std::vector<int> PmergeMe::getSortedVec() {
	std::vector<int> res;
	for (std::vector< std::pair<int, int> >::iterator it = v.begin(); it != v.end(); it++) {
		res.push_back(it->first);
	}
	return res;
}

std::list<int> PmergeMe::getSortedList() {
	std::list<int> res;
	for (std::list< std::pair<int, int> >::iterator it = l.begin(); it != l.end(); it++) {
		res.push_back(it->first);
	}
	return res;
}
