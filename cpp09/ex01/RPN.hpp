#ifndef RPN_HPP
# define RPN_HPP

# include <algorithm>
# include <stack>
# include <string>
# include <sstream>
# include <cctype>
# include <exception>

class RPN {
	private:
		std::string _input;
		RPN();
	public:
		RPN(std::string& input);
		RPN(const RPN& instance);
		~RPN();
		RPN& operator=(const RPN& rvalue);

		int run();
};

#endif
