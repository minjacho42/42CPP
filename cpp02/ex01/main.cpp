#include "Fixed.hpp"
#include <iostream>

int main()
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(-42.42f);

	a = Fixed(1234.4321f);
	std::cout << a.toInt() << " " << a << std::endl;
	std::cout << b.toInt() << " " << b << std::endl;
	std::cout << c.toInt() << " " << c << std::endl;
	std::cout.precision(10);
	std::cout << Fixed(FIXED_MAX) << std::endl; // 최대
	std::cout << Fixed(FIXED_MIN) << std::endl; // 최소
}
