# include "Replace.hpp"

Replace::Replace(std::string filename, std::string s1, std::string s2):
	filename(filename),
	s1(s1),
	s2(s2) {}

void Replace::pushReplacedString(std::string& of_buffer, std::ofstream &ofs)
{
	size_t find_res = of_buffer.find(s1);
	if (find_res == std::string::npos) {
		ofs << of_buffer.substr(0, of_buffer.length() - s1.length());
		of_buffer = of_buffer.substr(of_buffer.length() - s1.length());
	} else {
		ofs << of_buffer.substr(0, find_res);
		of_buffer = of_buffer.substr(find_res + s1.length());
		ofs << s2;
	}
}

void Replace::run()
{
	std::ifstream ifs;
	std::ofstream ofs;
	char *if_buffer = new char [s1.length() + 1];
	std::string of_buffer = "";

	ifs.open(filename, std::ifstream::in);
	if (!ifs.is_open())
	{
		std::cerr << "File Open Error\n";
		return ;
	}
	ofs.open(filename + ".replace", std::ofstream::out | std::ofstream::trunc);
	if (!ofs.is_open())
	{
		std::cerr << "File Open Error\n";
		return ;
	}
	for (size_t i = 0; i < s1.length(); i++)
		if_buffer[i] = '\0';
	ifs.read(if_buffer, s1.length());
	of_buffer.append(if_buffer);
	while (!(ifs.eof() || ifs.fail()))
	{
		ifs.read(if_buffer, s1.length());
		of_buffer.append(if_buffer);
		for (size_t i = 0; i < s1.length(); i++)
			if_buffer[i] = '\0';
		this->pushReplacedString(of_buffer, ofs);
	}
	ofs << of_buffer;
	delete[] if_buffer;
	ifs.close();
	ofs.close();
}
