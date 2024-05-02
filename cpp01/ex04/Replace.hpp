#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>
# include <iostream>
# include <fstream>

class Replace
{
	private:
		Replace();
		std::string s1;
		std::string s2;
		std::string filename;
	public:
		Replace(std::string filename, std::string s1, std::string s2);
		void run();
};

#endif
