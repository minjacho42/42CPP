#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "usage: ./btc <file>";
		return 1;
	}
	try {
		BitcoinExchange bitcoinExchange("data.csv");
		bitcoinExchange.run(argv[1]);
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
}
