# include "Replace.hpp"

Replace::Replace(std::string filename, std::string s1, std::string s2):
	filename(filename),
	s1(s1),
	s2(s2) {}

void Replace::pushReplacedString(std::string& of_buffer, std::ofstream &ofs, size_t read_len)
{
	size_t find_res = s1.length() != 0 ? of_buffer.find(s1) : std::string::npos;
	if (find_res == std::string::npos) {
		ofs << of_buffer.substr(0, of_buffer.length() - read_len);
		of_buffer = of_buffer.substr(of_buffer.length() - read_len);
	} else {
		ofs << of_buffer.substr(0, find_res);
		of_buffer = of_buffer.substr(find_res + read_len);
		ofs << s2;
	}
}

void Replace::run()
{
	std::ifstream ifs;
	std::ofstream ofs;
	size_t read_len = s1.length() == 0 ? 256 : s1.length();
	char *if_buffer = new char [read_len + 1];
	std::string of_buffer = "";

	if (read_len < 1)
	{
		delete[] if_buffer;
		return ;
	}
	ifs.open(filename, std::ifstream::in);
	if (!ifs.is_open())
	{
		std::cerr << "File Open Error\n";
		return ;
	}
	ofs.open(filename + ".replace", std::ofstream::out);
	if (!ofs.is_open())
	{
		std::cerr << "File Open Error\n";
		return ;
	}
	for (size_t i = 0; i < read_len; i++)
		if_buffer[i] = '\0';
	ifs.read(if_buffer, read_len);
	of_buffer.append(if_buffer);
	while (!(ifs.eof() || ifs.fail()))
	{
		for (size_t i = 0; i < read_len; i++)
			if_buffer[i] = '\0';
		ifs.read(if_buffer, read_len);
		of_buffer.append(if_buffer);
		this->pushReplacedString(of_buffer, ofs, read_len);
	}
	ofs << of_buffer;
	delete[] if_buffer;
	ifs.close();
	ofs.close();
}
