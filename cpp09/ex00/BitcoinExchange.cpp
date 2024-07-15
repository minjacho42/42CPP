#include "BitcoinExchange.hpp"

void BitcoinExchange::isValidDate(int y, int m, int d) {
	if (y < 1 || m < 1 || d < 1 || m > 12)
		throw std::invalid_argument("bad date input");
	bool leap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
	int max_date;
	if ((m < 8 && m % 2 == 1) || (m > 7 && m % 2 == 0)) {
		max_date = 31;
	} else {
		if (m == 2)
			max_date = leap ? 29 : 28;
		else
			max_date = 30;
	}
	if (d > max_date)
		throw std::invalid_argument("bad date input");
}

BitcoinExchange::BitcoinExchange(const std::string dbName) {
	std::ifstream istrm(dbName.c_str());
	std::string line;

	if (!istrm.is_open())
		throw std::invalid_argument("could not open file");
	std::getline(istrm, line);
	while (!istrm.eof()) {
		std::stringstream ss;
		int y, m, d;
		float price;
		char hyphen, comma;

		std::getline(istrm, line);
		if (!line.length())
			continue;
		ss.str(line);
		ss >> y >> hyphen >> m >> hyphen >> d >> comma >> price;
		if (ss.fail() || !ss.eof() || price < 0 || comma != ',') {
			throw std::invalid_argument("bad input");
		} else {
			isValidDate(y, m, d);
			unsigned int key = y;
			key *= 100;
			key += m;
			key *= 100;
			key += d;
			bitcoinPriceMap[key] = price;
		}
	}
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& instance) {
	*this = instance;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rvalue) {
	if (this != &rvalue) {
		this->bitcoinPriceMap = rvalue.bitcoinPriceMap;
	}
	return *this;
}

void BitcoinExchange::run(const std::string filename) {
	std::ifstream istrm(filename.c_str());
	std::string line;

	if (!istrm.is_open())
		throw std::invalid_argument("could not open file");
	std::getline(istrm, line);
	while (!istrm.eof()) {
		std::stringstream ss;
		int y, m, d;
		float count;
		char hyphen, bar;
		unsigned int key;

		std::getline(istrm, line);
		if (!line.length())
			continue;
		ss.str(line);
		try {
			ss >> y >> hyphen >> m >> hyphen >> d >> bar;
			if (ss.fail() || bar != '|') {
				throw std::invalid_argument("bad input");
			} else {
				isValidDate(y, m, d);
				key = y;
				key *= 100;
				key += m;
				key *= 100;
				key += d;
				if (bitcoinPriceMap.begin()->first > key) {
					throw std::invalid_argument("date is out of range");
				}
			}
			ss >> count;
			if (!ss.eof() || ss.fail()) {
				throw std::invalid_argument("bad input");
			} else {
				if (count > 1000)
					throw std::invalid_argument("number is too big");
				if (count <= 0)
					throw std::invalid_argument("invalid number");
				std::map<unsigned int, float>::iterator it = bitcoinPriceMap.upper_bound(key);
				it--;
				std::cout << y << "-" << std::setfill('0') << std::setw(2) << m << "-" << std::setfill('0') << std::setw(2) << d << " => " << count << " = " << it->second * count << std::endl;
			}
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}
