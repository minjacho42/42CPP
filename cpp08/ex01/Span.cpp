#include "Span.hpp"

Span::Span(): N(0) {}

Span::Span(unsigned int n): N(n) {
}

Span::Span(const Span& instance) {
	N = instance.N;
	v = instance.v;
}

Span::~Span() {}

Span& Span::operator=(const Span& rvalue) {
	if (this != &rvalue) {
		this->N = rvalue.N;
		this->v = rvalue.v;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (v.size() >= N)
		throw std::out_of_range("Span Is Full");
	else
		v.push_back(num);
}

void Span::addNumberByArray(const std::list<int> l) {
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); it++)
		addNumber(*it);
}

unsigned int Span::shortestSpan() const {
	unsigned int res;
	bool init = false;

	if (v.size() < 2)
		throw std::length_error("Span size is less then 2");
	for (std::vector<int>::const_iterator it1 = v.begin(); it1 != v.end(); it1++) {
		for (std::vector<int>::const_iterator it2 = it1 + 1; it2 != v.end(); it2++) {
			unsigned int new_res = *it1 > *it2 ? *it1 - *it2 : *it2 - *it1;
			if (!init) {
				res = new_res;
				init = true;
			} else {
				res = std::min(res, new_res);
			}
		}
	}
	return res;
}

unsigned int Span::longestSpan() const {
	int	min_val;
	int	max_val;

	if (v.size() < 2)
		throw std::length_error("Span size is less then 2");
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		if (it == v.begin()) {
			min_val = *it;
			max_val = *it;
		} else {
			min_val = std::min(min_val, *it);
			max_val = std::max(max_val, *it);
		}
	}
	return max_val - min_val;
}
