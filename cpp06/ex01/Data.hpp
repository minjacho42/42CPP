#ifndef DATA_HPP
# define DATA_HPP

# include <string>
# include <iostream>

class Data
{
	private:
		int		_i;
		float	_f;
		double	_d;
		Data();
	public:
		Data(const Data& instance);
		Data(int i, float f, double d);
		Data& operator=(const Data& rvalue);
		int	getInt(void) const;
		float	getFloat(void) const;
		double	getDouble(void) const;
		~Data();
};

std::ostream& operator<<(std::ostream& os, const Data& rvalue);


#endif
