#include "Data.hpp"

Data::Data(int i, float f, double d): _i(i), _f(f), _d(d)
{}

Data::Data(const Data& instance)
{
	*this = instance;
}

Data& Data::operator=(const Data& rvalue)
{
	if (this == &rvalue)
		return (*this);
	this->_d = rvalue._d;
	this->_f = rvalue._f;
	this->_i = rvalue._i;
	return (*this);
}

Data::~Data() {}

int Data::getInt(void) const
{
	return (this->_i);
}

float Data::getFloat(void) const
{
	return (this->_f);
}

double Data::getDouble(void) const
{
	return (this->_d);
}

std::ostream& operator<<(std::ostream& os, const Data& rvalue)
{
	os << "Inteager: " << rvalue.getInt() << "\n";
	os << "Float: " << rvalue.getFloat() << "\n";
	os << "Double: " << rvalue.getDouble();
	return (os);
}
