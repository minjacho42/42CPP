#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& left, T& right)
{
	T tmp = left;
	left = right;
	right = tmp;
}

template <typename T>
T& min(T& first, T& second)
{
	return (second > first ? first : second);
}

template <typename T>
T& max(T& first, T& second)
{
	return (second < first ? first : second);
}

#endif
