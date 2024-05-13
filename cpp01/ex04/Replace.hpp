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
		static const std::streamsize read_len = 256;
	public:
		Replace(const std::string& filename, const std::string& s1, const std::string& s2);
		void run();
};

#endif
