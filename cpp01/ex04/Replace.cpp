# include <Replace.hpp>

Replace::Replace(std::string filename, std::string s1, std::string s2):
	filename(filename),
	s1(s1),
	s2(s2) {}

void Replace::run()
{
	std::ifstream ifs;
	std::ofstream ofs;
	char *if_buffer = new char [s1.length()];
	std::string of_buffer = "";
	size_t find_res;

	ifs.open(filename, std::ifstream::in);
	ofs.open(filename + ".replace", std::ofstream::out);
	ifs.read(if_buffer, s1.length());
	of_buffer.append(if_buffer);
	while (!ifs.eof())
	{
		ifs.read(if_buffer, s1.length());
		of_buffer.append(if_buffer);
		find_res = of_buffer.find(s1);
		if (find_res == std::string::npos) {
			ofs << of_buffer.substr(0, of_buffer.length() - s1.length());
			of_buffer = of_buffer.substr(of_buffer.length() - s1.length());
		} else {
			ofs << of_buffer.substr(0, find_res);
			of_buffer = of_buffer.substr(find_res + s1.length());
			ofs << s2;
		}
	}
}
