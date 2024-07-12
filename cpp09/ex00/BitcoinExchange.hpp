#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <algorithm>
# include <map>
# include <string>
# include <iostream>
# include <exception>
# include <fstream>
# include <sstream>

class BitcoinExchange {
	private:
		std::map<std::string, float> bitcoinPriceMap;

		BitcoinExchange();

	public:
		BitcoinExchange(const std::string dbName);
		BitcoinExchange(const BitcoinExchange& instance);
		BitcoinExchange& operator=(const BitcoinExchange& rvalue);
		~BitcoinExchange();

		void run(const std::string filename);

		class FileOpenError: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
