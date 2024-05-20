#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <fstream>
# include <cmath>

# define FIXED_MAX 8388607
# define FIXED_MIN -8388608

class Fixed
{
	private:
		int raw_value;
		static const int fractional_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& instance);
		Fixed(const int integer);
		Fixed(const float number);
		~Fixed();
		Fixed& operator=(const Fixed& rvalue);
		int getRawBits(void) const; //맴버 변수들의 값을 바꾸지 않는 함수.
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& rvalue);

#endif
