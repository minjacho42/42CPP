#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>
# include <fstream>
# include <iostream>

class Replace
{
	private:
		Replace();
		const std::string filename;
		const std::string s1;
		const std::string s2;
		void pushReplacedString(std::string& of_buffer, std::ofstream& ofs, const size_t read_len);
	public:
		Replace(const std::string& filename, const std::string& s1, const std::string& s2);
		void run();
};

#endif
