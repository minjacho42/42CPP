# include <Replace.hpp>

Replace::Replace(std::string filename, std::string s1, std::string s2):
	filename(filename),
	s1(s1),
	s2(s2) {}

void Replace::run()
{
	std::ifstream ifs;
	std::ofstream ofs;
	char *if_buffer = new char [this->s1.length()];
	std::string of_buffer = "";

	ifs.open(this->filename, std::ifstream::in);
	ofs.open(this->filename + ".replace", std::ofstream::out);
	ifs.read(if_buffer, this->s1.length());
	of_buffer.append(if_buffer);
	while (!ifs.eof())
	{
		ifs.read(if_buffer, this->s1.length());
		of_buffer.append(if_buffer);
	}
}
