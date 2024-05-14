# include "Fixed.hpp"

Fixed::Fixed(): raw_value(0)
{
	std::cout << "Default constructor called (Fixed)\n";
}

Fixed::Fixed(const Fixed& instance)
{
	std::cout << "Copy constructor called (Fixed)\n";
	*this = instance;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Integer constructor called (Fixed)\n";
	raw_value = integer;
	raw_value <<= fractional_bits;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called (Fixed)\n";
	raw_value = std::floor(number * std::pow(2, fractional_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called (Fixed)\n";
}

Fixed& Fixed::operator=(const Fixed& rvalue)
{
	std::cout << "Copy assignment operator called (Fixed)\n";
	this->raw_value = rvalue.raw_value;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called (Fixed)\n";
	return (this->raw_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called (Fixed)\n";
	this->raw_value = raw;
}

float Fixed::toFloat(void) const
{
	float number_f;

	number_f = raw_value;
	for (int i = 0; i < fractional_bits; i++)
		number_f /= 2;
	return number_f;
}

int Fixed::toInt(void) const
{
	int number_i;

	number_i = raw_value;
	for (int i = 0; i < fractional_bits; i++)
		number_i /= 2;
	return number_i;
}

std::ostream& operator<<(std::ostream& os, const Fixed& rvalue)
{
	os << rvalue.toFloat();
	return os;
}
