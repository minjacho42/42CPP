#include "Fixed.hpp"
#include <iostream>

int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// Fixed const b( Fixed( 0.5f ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout.precision(10);
	std::cout << Fixed(FIXED_MAX) / Fixed(FIXED_MAX) << std::endl;
	std::cout << Fixed(FIXED_MIN) / Fixed(1000)<< std::endl;
	return 0;
}
