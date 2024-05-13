# include "Fixed.hpp"

Fixed::Fixed(): raw_value(0)
{
	std::cout << "Default constructor called (Fixed)\n";
}

Fixed::Fixed(Fixed& instance)
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
	int dot_left;
	float dot_right_f;

	std::cout << "Float constructor called (Fixed)\n";
	dot_left = (int) number > 0 ? std::floor(number) : std::ceil(number);
	dot_right_f = std::abs(number - dot_left);
	raw_value = dot_left > 0 ? dot_left : dot_left * -1;
	for (int i = 0; i < fractional_bits; i++)
	{
		raw_value <<= 1;
		dot_right_f *= 2;
		raw_value += (int)std::floor(dot_right_f);
		dot_right_f -= std::floor(dot_right_f);
	}
	raw_value = number > 0 ? raw_value : -raw_value;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called (Fixed)\n";
}

Fixed& Fixed::operator=(const Fixed& rvalue)
{
	std::cout << "Copy assignment operator called (Fixed)\n";
	this->raw_value = rvalue.getRawBits();
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

bool Fixed::operator<(const Fixed& rhs) const
{
	return (raw_value < rhs.getRawBits());
}

bool Fixed::operator>(const Fixed& rhs) const
{
	return (raw_value > rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	return (raw_value <= rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	return (raw_value >= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed& rhs) const
{
	return (raw_value == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	return (raw_value != rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed& rvalue) const
{
	Fixed result = Fixed(this->raw_value);

	result.raw_value += rvalue.raw_value;
	return (result);
}

Fixed Fixed::operator-(const Fixed& rvalue) const
{
	Fixed result = Fixed(this->raw_value);

	result.raw_value -= rvalue.raw_value;
	return (result);
}

Fixed Fixed::operator*(const Fixed& rvalue) const
{
	Fixed result = Fixed(this->raw_value);

	result.raw_value *= rvalue.raw_value;
	return (result);
}

Fixed Fixed::operator/(const Fixed& rvalue) const
{
	Fixed result = Fixed(this->raw_value);

	result.raw_value /= rvalue.raw_value;
	return (result);
}

Fixed& Fixed::operator++()
{
	this->raw_value += (1 << 8);
	return *this;
}

Fixed& Fixed::operator--()
{
	this->raw_value -= (1 << 8);
	return *this;
}

Fixed Fixed::operator++(int dummy)
{
	dummy += 0;
	this->raw_value += (1 << 8);
	return *this;
}

Fixed Fixed::operator--(int dummy)
{
	dummy += 0;
	this->raw_value -= (1 << 8);
	return *this;
}

static Fixed& min(Fixed& lhs, Fixed& rhs)
{
	return (lhs.getRawBits() < rhs.getRawBits() ? lhs : rhs);
}

static Fixed& min(const Fixed& lhs, const Fixed& rhs)
{
	return (lhs.getRawBits() < rhs.getRawBits() ? lhs : rhs);
}

static Fixed& max(Fixed& lhs, Fixed& rhs)
{
	return (lhs.getRawBits() > rhs.getRawBits() ? lhs : rhs);
}

static Fixed& max(const Fixed& lhs, const Fixed& rhs)
{
	return (lhs.getRawBits() > rhs.getRawBits() ? lhs : rhs);
}
