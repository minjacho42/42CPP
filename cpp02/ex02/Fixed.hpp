#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <fstream>
# include <cmath>

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
		bool operator<(const Fixed& rhs) const;
		bool operator>(const Fixed& rhs) const;
		bool operator<=(const Fixed& rhs) const;
		bool operator>=(const Fixed& rhs) const;
		bool operator==(const Fixed& rhs) const;
		bool operator!=(const Fixed& rhs) const;
		Fixed operator+(const Fixed& rvalue) const;
		Fixed operator-(const Fixed& rvalue) const;
		Fixed operator*(const Fixed& rvalue) const;
		Fixed operator/(const Fixed& rvalue) const;
		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		static Fixed& min(Fixed& lhs, Fixed& rhs);
		static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
		static Fixed& max(Fixed& lhs, Fixed& rhs);
		static const Fixed& max(const Fixed& lhs, const Fixed& rhs);
};

std::ostream& operator<<(std::ostream& os, const Fixed& rvalue);

#endif
