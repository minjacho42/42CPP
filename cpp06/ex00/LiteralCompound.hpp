#ifndef LITERALCOMPOUND_HPP
# define LITERALCOMPOUND_HPP

# include <string>
# include <iostream>

class LiteralCompound
{
	private:
		bool	c_b;
		char	c;
		bool	i_b;
		int		i;
		bool	f_b;
		float	f;
		std::string f_str;
		bool	d_b;
		std::string d_str;
		double	d;
		bool	fail;


	public:
		LiteralCompound();
		LiteralCompound(const LiteralCompound& instance);
		LiteralCompound&	operator=(const LiteralCompound& rvalue);
		~LiteralCompound();
		LiteralCompound(char c);
		LiteralCompound(int i, bool overflow);
		LiteralCompound(float f, const std::string& raw_value);
		LiteralCompound(double d, const std::string& raw_value);
		bool	getCharBool() const;
		bool	getIntBool() const;
		bool	getFloatBool() const;
		bool	getDoubleBool() const;
		std::string getStringFloat() const;
		std::string getStringDouble() const;
		char	getChar() const;
		int		getInt() const;
		float	getFloat() const;
		double	getDouble() const;
		bool getFail() const;
};

std::ostream& operator<<(std::ostream& os, const LiteralCompound& rvalue);

#endif
