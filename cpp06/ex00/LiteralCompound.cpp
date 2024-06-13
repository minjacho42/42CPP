#include "LiteralCompound.hpp"

LiteralCompound::LiteralCompound()
{
	fail = true;
}

LiteralCompound::LiteralCompound(char c)
{
	fail = false;
	c_b = true;
	this->c = c;
	i_b = true;
	i = static_cast<int>(c);
	f_b = true;
	f = static_cast<float>(c);
	d_b = true;
	d = static_cast<double>(c);
}

LiteralCompound::LiteralCompound(int i, bool overflow)
{
	fail = false;
	if (overflow)
	{
		c_b = false;
		i_b = false;
		f_b = false;
		f_str = "impossible";
		d_b = false;
		d_str = "impossible";
	}
	else
	{
		i_b = true;
		this->i = i;
		f_b = true;
		f = static_cast<float>(i);
		d_b = true;
		d = static_cast<double>(i);
		if (i < -256 || i > 255)
			c_b = false;
		else
		{
			c_b = true;
			c = static_cast<char>(i);
		}
	}
}

LiteralCompound::LiteralCompound(float f, const std::string& raw_value)
{
	fail = false;
	if (raw_value.compare("nanf") == 0 || raw_value.compare("-nanf") == 0 || raw_value.compare("inff") == 0 || raw_value.compare("-inff") == 0)
	{
		c_b = false;
		i_b = false;
		f_b = false;
		d_b = false;
		f_str = raw_value;
		d_str = raw_value.substr(0, raw_value.length() - 1);
	}
	else
	{
		f_b = true;
		this->f = f;
		d_b = true;
		this->d = static_cast<double>(f);
		if (f < -2147483648 || f > 2147483647)
			i_b = false;
		else
		{
			i_b = true;
			i = static_cast<int>(f);
		}
		if (f < -256 || f > 255)
			c_b = false;
		else
		{
			c_b = true;
			c = static_cast<char>(f);
		}
	}
}

LiteralCompound::LiteralCompound(double d, const std::string& raw_value)
{
	fail = false;
	if (raw_value.compare("inf") == 0 || raw_value.compare("-inf") == 0 || raw_value.compare("nan") == 0 || raw_value.compare("-nan") == 0)
	{
		c_b = false;
		i_b = false;
		f_b = false;
		d_b = false;
		f_str = raw_value + "f";
		d_str = raw_value;
	}
	else
	{
		d_b = true;
		this->d = d;
		f_b = true;
		this->f = static_cast<float>(d);
		if (d < -2147483648 || d > 2147483647)
			i_b = false;
		else
		{
			i_b = true;
			i = static_cast<int>(d);
		}
		if (d < -256 || d > 255)
			c_b = false;
		else
		{
			c_b = true;
			c = static_cast<char>(d);
		}
	}
}

LiteralCompound::LiteralCompound(const LiteralCompound& instance)
{
	*this = instance;
}

LiteralCompound& LiteralCompound::operator=(const LiteralCompound& rvalue)
{
	if (this == &rvalue)
		return (*this);
	this->fail = rvalue.fail;
	this->c = rvalue.c;
	this->c_b = rvalue.c_b;
	this->i = rvalue.i;
	this->i_b = rvalue.i_b;
	this->f = rvalue.f;
	this->f_b = rvalue.f_b;
	this->f_str = rvalue.f_str;
	this->d = rvalue.d;
	this->d_b = rvalue.d_b;
	this->d_str = rvalue.d_str;
	return (*this);
}

LiteralCompound::~LiteralCompound()
{
}

bool	LiteralCompound::getCharBool() const
{
	return (this->c_b);
}

bool	LiteralCompound::getIntBool() const
{
	return (this->i_b);
}

bool	LiteralCompound::getFloatBool() const
{
	return (this->f_b);
}

bool	LiteralCompound::getDoubleBool() const
{
	return (this->d_b);
}

char	LiteralCompound::getChar() const
{
	return (this->c);
}

int	LiteralCompound::getInt() const
{
	return (this->i);
}

float	LiteralCompound::getFloat() const
{
	return (this->f);
}

std::string LiteralCompound::getStringFloat() const
{
	return (this->f_str);
}

double	LiteralCompound::getDouble() const
{
	return (this->d);
}

std::string LiteralCompound::getStringDouble() const
{
	return (this->d_str);
}

bool LiteralCompound::getFail() const
{
	return (this->fail);
}

std::ostream& operator<<(std::ostream& os, const LiteralCompound& rvalue)
{
	if (rvalue.getFail())
	{
		os << "Not Valid Input";
		return os;
	}
	os << "char: ";
	if (!rvalue.getCharBool())
		os << "impossible";
	else if (isprint(rvalue.getChar()))
		os << "'" << rvalue.getChar() << "'";
	else
		os << "Non displayable";
	os << "\n";
	os << "int: ";
	if (!rvalue.getIntBool())
		os << "impossible";
	else
		os << rvalue.getInt();
	os << "\n";
	os << "float: ";
	if (!rvalue.getFloatBool())
		os << rvalue.getStringFloat();
	else
		os << rvalue.getFloat() << "f";
	os << "\n";
	os << "double: ";
	if (!rvalue.getDoubleBool())
		os << rvalue.getStringDouble();
	else
		os << rvalue.getDouble();
	return os;
}
