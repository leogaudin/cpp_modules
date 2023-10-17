#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <ctime>

class BitcoinExchange
{
  public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &bitcoinexchange);
	BitcoinExchange &operator=(const BitcoinExchange &bitcoinexchange);
	~BitcoinExchange();
	void parseInput(std::string input_file);

  private:
	std::map<std::string, float> _map;
	std::map<std::string, float> parseFile();
	float getPrice(std::string date, double value);
};

#endif
