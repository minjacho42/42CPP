#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <algorithm>
# include <map>
# include <string>
# include <iostream>
# include <exception>
# include <fstream>
# include <sstream>
# include <iomanip>

class BitcoinExchange {
	private:
		std::map<unsigned int, float> bitcoinPriceMap;

		BitcoinExchange();
		void isValidDate(int y, int m, int d);
	public:
		BitcoinExchange(const std::string dbName);
		BitcoinExchange(const BitcoinExchange& instance);
		BitcoinExchange& operator=(const BitcoinExchange& rvalue);
		~BitcoinExchange();

		void run(const std::string filename);
};

#endif
