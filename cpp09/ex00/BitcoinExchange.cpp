#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string dbName) {
	std::ifstream istrm(dbName.c_str());
	std::string line;

	if (!istrm.is_open())
		throw BitcoinExchange::FileOpenError();
	// std::getline(istrm, line);
	while (!istrm.eof()) {
		std::stringstream ss;
		int y, m, d;
		float price;
		char hyphen, comma;

		std::getline(istrm, line);
		ss.str(line);
		ss >> y >> hyphen >> m >> hyphen >> d >> comma >> price;
		if (ss.fail() || !ss.eof()) {

		}
	}
}

BitcoinExchange::~BitcoinExchange() {

}

void BitcoinExchange::run(const std::string filename) {
	std::cout << filename << std::endl;
}

const char* BitcoinExchange::FileOpenError::what() const throw() {
	return ("could not open file.");
}
