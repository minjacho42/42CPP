# include "Replace.hpp"

Replace::Replace(const std::string& filename, const std::string& s1, const std::string& s2):
	filename(filename),
	s1(s1),
	s2(s2) {}

void Replace::run()
{
	std::ifstream ifs;
	std::ofstream ofs;
	std::streambuf *buf;
	char *if_buffer = new char [read_len + 1];
	std::string of_buffer = "";
	std::streamsize read_size = read_len;
	size_t find_res;

	ifs.open(filename.c_str(), std::ifstream::in);
	if (!ifs.is_open())
	{
		std::cerr << "File Open Error\n";
		return ;
	}
	ofs.open((filename + ".replace").c_str(), std::ofstream::out);
	if (!ofs.is_open())
	{
		std::cerr << "File Open Error\n";
		return ;
	}
	buf = ifs.rdbuf();
	while (read_size >= read_len)
	{
		read_size = buf->sgetn(if_buffer, read_len);
		if_buffer[read_size] = 0;
		of_buffer.append(if_buffer);
	}
	while ((find_res = of_buffer.find(s1)) != std::string::npos)
	{
		ofs << of_buffer.substr(0, find_res);
		of_buffer = of_buffer.substr(find_res + s1.length());
		ofs << s2;
	}
	ofs << of_buffer;
	delete[] if_buffer;
	ifs.close();
	ofs.close();
}
