#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <list>
# include <iterator>
# include <algorithm>
# include <exception>
# include <iterator>

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	v;

		Span();
	public:
		Span(unsigned int n);
		Span(const Span& instance);
		Span& operator=(const Span& rvalue);
		~Span();

		void addNumber(int num); // 만약 이미 들어있는 숫자의 개수가 N개이면 exception

		template <typename T>
		void addNumber(typename T::iterator begin, typename T::iterator end) {
			typename T::iterator it = begin;
			while (it != end) {
				addNumber(*it);
				it++;
			}
		}

		template <typename T>
		void addNumber(typename T::const_iterator begin, typename T::const_iterator end) {
			typename T::const_iterator it = begin;
			while (it != end) {
				addNumber(*it);
				it++;
			}
		}

		void addNumberByArray(const std::list<int> l);
		unsigned int shortestSpan() const; // Span 내부에 있는 수의 개수가 1개 또는 없으면 exception
		unsigned int longestSpan() const; // Span 내부에 있는 수의 개수가 1개 또는 없으면 exception
};

#endif
