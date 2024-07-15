#include "RPN.hpp"
#include <iostream>

RPN::RPN(std::string &input): _input(input) {}

RPN::~RPN() {}

RPN::RPN(const RPN& instance) {
	*this = instance;
}

RPN& RPN::operator=(const RPN& rvalue) {
	if (this != &rvalue) {
		this->_input = rvalue._input;
	}
	return *this;
}

int RPN::run() {
	std::stack<int> s;
	std::stringstream ss;

	ss.str(_input);
	while (!ss.eof()) {
		char c;
		ss >> c;
		if (ss.eof())
			break;
		if (isdigit(c)) {
			s.push(c - '0');
		} else {
			if (c == '+' || c == '-' || c == '/' || c == '*') {
				int lhs;
				int rhs;
				int res = 0;
				if (s.size() < 2)
					throw std::invalid_argument("Not valid expression");
				rhs = s.top();
				s.pop();
				lhs = s.top();
				s.pop();
				switch (c) {
					case '+':
						res = lhs + rhs;
						break;
					case '-':
						res = lhs - rhs;
						break;
					case '*':
						res = lhs * rhs;
						break;
					case '/':
						if (rhs == 0)
							throw std::invalid_argument("Divide by zero");
						res = lhs / rhs;
						break;
					default:
						break;
				}
				s.push(res);
			} else {
				throw std::invalid_argument("Not valid operator");
			}
		}
	}
	if (s.size() != 1)
		throw std::invalid_argument("Not valid expression");
	return (s.top());
}
