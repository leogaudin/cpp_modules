#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange bitcoinExchange;
	if (argc == 2)
	{
		bitcoinExchange.parseInput(argv[1]);
	}
	else
		std::cout << "Usage: ./bitcoin [input_file]" << std::endl;
	return (0);
}
