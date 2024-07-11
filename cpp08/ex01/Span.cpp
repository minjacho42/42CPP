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
	if (v.size() >= N) {
		throw std::out_of_range("Span Is Full");
	} else {
		std::vector<int>::iterator it = std::lower_bound(v.begin(), v.end(), num);
		v.insert(it, num);
	}
}

void Span::addNumberByArray(const std::list<int> l) {
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); it++)
		addNumber(*it);
}

unsigned int Span::shortestSpan() const {
	unsigned int res = longestSpan();
	int before;

	if (v.size() < 2)
		throw std::length_error("Span size is less then 2");
	before = v[0];
	for (std::vector<int>::const_iterator it = v.begin() + 1; it != v.end(); it++) {
		unsigned int cur = *it - before;
		res = std::min(res, cur);
		before = *it;
	}
	return res;
}

unsigned int Span::longestSpan() const {
	if (v.size() < 2)
		throw std::length_error("Span size is less then 2");
	return v[v.size() - 1] - v[0];
}

void Span::printer() const {
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		if (it != v.begin())
			std::cout << ", ";
		std::cout << *it;
	}
	std::cout << std::endl;
}
