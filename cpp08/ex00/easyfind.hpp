#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iterator>
# include <algorithm>
# include <exception>

template <typename T>
typename T::iterator easyfind(T c, int i) {
	typename T::iterator it;
	if ((it = std::find(c.begin(), c.end(), i)) == c.end()) {
		throw std::out_of_range("Couldn't find value");
	}
	return it;
}

#endif
