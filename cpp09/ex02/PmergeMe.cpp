#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(int ac, char **av) {
	n = ac - 1;
	level = std::ceil(log2(n));
	k = std::pow(2, level);
	for (int i = 0; i < k; i++) {
		int num = i < n ? std::atoi(av[i + 1]) : -1;
		if (i < n && num < 0) {
			throw std::invalid_argument("argument is not a postivie number");
		}
		pair_v.push_back(num);
		pair_d.push_back(num);
	}
}

PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe& instance) {
	*this = instance;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rvalue) {
	if (this != &rvalue) {
		this->pair_v = rvalue.pair_v;
		this->pair_d = rvalue.pair_d;
	}
	return *this;
}

void PmergeMe::initPairV() {
	for (int lv = 0; lv < level; lv++) {
		int step = std::pow(2, lv);
		for (int i = 0; i < k; i += step) {
			if (pair_v[i] < pair_v[i + step / 2]) {
				for (int j = i; j < i + step / 2; j++)
					std::swap(pair_v[j], pair_v[j + step / 2]);
			}
		}
	}
}

void PmergeMe::initPairD() {
	for (int lv = 0; lv < level; lv++) {
		int step = std::pow(2, lv);
		for (int i = 0; i < k; i += step) {
			if (pair_d[i] < pair_d[i + step / 2]) {
				for (int j = i; j < i + step / 2; j++)
					std::swap(pair_d[j], pair_d[j + step / 2]);
			}
		}
	}
}

bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	return a.first < b.first;
}

void PmergeMe::runVector() {
	initPairV();
	v.push_back(std::make_pair(pair_v[0], 0));
	for (int lv = level - 1; lv > -1; lv--) {
		// std::cout << "------\nlevel : " << lv << std::endl;
		std::vector< std::pair<int, int> > single_tmp;
		std::vector< std::pair<int, int> > tmp_v;
		for (std::vector< std::pair<int, int> >::iterator it = v.begin(); it != v.end(); it++) {
			int pair_idx = it->second + std::pow(2, lv);
			if (pair_v[pair_idx] < 0)
				single_tmp.push_back(*it);
			else
				tmp_v.push_back(*it);
		}
		for (std::vector< std::pair<int, int> >::iterator it = single_tmp.begin(); it != single_tmp.end(); it++) {
			v.erase(std::find(v.begin(), v.end(), *it));
		}
		// std::cout << "single size : " << single_tmp.size() << std::endl;
		int start_idx = 0;
		// std::cout << "size : " << tmp_v.size() << std::endl;
		int jacob = 0;
		while (start_idx < static_cast<int>(tmp_v.size())) {
			for (int i = start_idx + jacob; i >= start_idx; i--) {
				int pair_idx = tmp_v[i].second + std::pow(2, lv);
				if (pair_v[pair_idx] < 0) {
					continue;
				}
				std::pair<int, int> new_pair = std::make_pair(pair_v[pair_idx], pair_idx);
				std::vector<std::pair<int, int> >::iterator it = std::find(v.begin(), v.end(), tmp_v[i]);
				v.insert(std::lower_bound(v.begin(), it, new_pair, comparePairs), new_pair);
			}
			start_idx += (jacob + 1);
			int size_before = start_idx * 2 + 1;
			jacob = std::pow(2, std::floor(log2(size_before)) + 1) - size_before - 1;
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

void PmergeMe::runDeque() {
	initPairD();
	d.push_back(std::make_pair(pair_d[0], 0));
	for (int lv = level - 1; lv > -1; lv--) {
		// std::cout << "------\nlevel : " << lv << std::endl;
		std::deque< std::pair<int, int> > single_tmp;
		std::deque< std::pair<int, int> > tmp_d;
		for (std::deque< std::pair<int, int> >::iterator it = d.begin(); it != d.end(); it++) {
			int pair_idx = it->second + std::pow(2, lv);
			if (pair_d[pair_idx] < 0)
				single_tmp.push_back(*it);
			else
				tmp_d.push_back(*it);
		}
		for (std::deque< std::pair<int, int> >::iterator it = single_tmp.begin(); it != single_tmp.end(); it++) {
			d.erase(std::find(d.begin(), d.end(), *it));
		}
		// std::cout << "single size : " << single_tmp.size() << std::endl;
		int start_idx = 0;
		// std::cout << "size : " << tmp_d.size() << std::endl;
		int jacob = 0;
		while (start_idx < static_cast<int>(tmp_d.size())) {
			for (int i = start_idx + jacob; i >= start_idx; i--) {
				int pair_idx = tmp_d[i].second + std::pow(2, lv);
				if (pair_d[pair_idx] < 0) {
					continue;
				}
				std::pair<int, int> new_pair = std::make_pair(pair_d[pair_idx], pair_idx);
				std::deque<std::pair<int, int> >::iterator it = std::find(d.begin(), d.end(), tmp_d[i]);
				d.insert(std::lower_bound(d.begin(), it, new_pair, comparePairs), new_pair);
			}
			start_idx += (jacob + 1);
			int size_before = start_idx * 2 + 1;
			jacob = std::pow(2, std::floor(log2(size_before)) + 1) - size_before - 1;
			if (jacob < 0)
				jacob = 0;
			// std::cout << start_idx << " " << size_before << " " << jacob + 1 << std::endl;
			if (jacob > static_cast<int>(tmp_d.size()) - start_idx - 1)
				jacob = static_cast<int>(tmp_d.size()) - start_idx - 1;
		}
		for (std::deque< std::pair<int, int> >::iterator it = single_tmp.begin(); it != single_tmp.end(); it++) {
			std::pair<int, int> new_pair = *it;
			d.insert(std::lower_bound(d.begin(), d.end(), new_pair, comparePairs), new_pair);
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

std::deque<int> PmergeMe::getSortedDeque() {
	std::deque<int> res;
	for (std::deque< std::pair<int, int> >::iterator it = d.begin(); it != d.end(); it++) {
		res.push_back(it->first);
	}
	return res;
}
