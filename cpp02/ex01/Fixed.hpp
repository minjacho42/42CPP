#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int raw_value;
		static const int fractional_bits = 8;
	public:
		Fixed();
		Fixed(Fixed& instance);
		Fixed(const int integer);
		Fixed(const double number);
		~Fixed();
		Fixed& operator=(const Fixed& rvalue);
		int getRawBits(void) const; //맴버 변수들의 값을 바꾸지 않는 함수.
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

#endif
