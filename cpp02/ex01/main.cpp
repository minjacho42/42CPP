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
}
