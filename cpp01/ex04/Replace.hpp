#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>
# include <fstream>
# include <iostream>

class Replace
{
	private:
		Replace();
		std::string filename;
		std::string s1;
		std::string s2;
		void pushReplacedString(std::string& of_buffer, std::ofstream &ofs, size_t read_len);
	public:
		Replace(std::string filename, std::string s1, std::string s2);
		void run();
};

#endif
