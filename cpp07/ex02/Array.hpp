#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array
{
	private:
		T			*_arr;
		std::size_t	_size;
	public:
		Array()
		{
			_size = 0;
			_arr = NULL;
		}

		Array(unsigned int n)
		{
			_size = n;
			_arr = new T[n];
		}

		Array(const Array& instance)
		{
			_arr = NULL;
			*this = instance;
		}

		~Array()
		{
			delete _arr;
		}

		Array&		operator=(const Array& rvalue)
		{
			if (this == &rvalue)
				return (*this);
			if (_arr)
				delete _arr;
			_arr = new T[rvalue._size];
			_size = rvalue._size;
			for (unsigned int i = 0; i < _size; i++)
				_arr[i] = rvalue._arr[i];
			return (*this);
		}

		T&			operator[](std::size_t n)
		{
			if (n >= _size)
				throw std::out_of_range("Index Out Of Range");
			return (_arr[n]);
		}

		const T&	operator[](std::size_t n) const
		{
			if (n >= _size)
				throw std::out_of_range("Index Out Of Range");
			return (_arr[n]);
		}

		std::size_t	size() const
		{
			return (_size);
		}
};

#endif
