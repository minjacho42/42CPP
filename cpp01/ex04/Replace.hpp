#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>
# include <fstream>

class Replace
{
	private:
		Replace();
		std::string filename;
		std::string s1;
		std::string s2;
	public:
		Replace(std::string filename, std::string s1, std::string s2);
		void run();
		void pushReplacedString(std::string& of_buffer, std::ofstream &ofs);
};

#endif
