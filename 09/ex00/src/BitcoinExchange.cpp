#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// std::cout << "BitcoinExchange: Default constructor called" << std::endl;
    this->_map = parseFile();
}

BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "BitcoinExchange: Destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinexchange)
{
	// std::cout << "BitcoinExchange: Copy constructor called" << std::endl;
	this->_map = bitcoinexchange._map;
	*this = bitcoinexchange;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bitcoinexchange)
{
	// std::cout << "BitcoinExchange: Copy assignment operator called" << std::endl;
	this->_map = bitcoinexchange._map;
	return (*this);
}

std::map<std::string, float> BitcoinExchange::parseFile()
{
	std::ifstream ifs("./data.csv");
	std::map<std::string, float> dataMap;
	std::string line;

	if (!ifs.is_open())
		return (std::cerr << "Error opening ifs." << std::endl, dataMap);

	while (std::getline(ifs, line))
	{
		if (!line.compare("date,exchange_rate"))
			continue;
		std::istringstream lineStream(line);
		std::string dateStr, valueStr;
		if (std::getline(lineStream, dateStr, ','))
		{
			if (std::getline(lineStream, valueStr, ','))
			{
				try
				{
					dataMap[dateStr] = std::stof(valueStr);
				}
				catch (const std::exception &e)
                {
					std::cerr << "Error parsing line: " << e.what() << std::endl;
                }
			}
			else
				std::cerr << "Error parsing line: Expected a float value." << std::endl;
		}
		else
			std::cerr << "Error parsing line: Expected a date." << dateStr << std::endl;
	}
	ifs.close();

    // for (std::map<std::string, float>::iterator it = dataMap.begin(); it != dataMap.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';

	return (dataMap);
}

float BitcoinExchange::getPrice(std::string date, double value)
{
	std::map<std::string, float>::iterator it = this->_map.find(date);

	while (it == this->_map.end())
	{
		try
		{
			std::tm tm = {};
			std::istringstream ss(date);
			ss >> std::get_time(&tm, "%Y-%m-%d");
			if (ss.fail())
				throw std::runtime_error("bad date => " + date);
			tm.tm_mday--;
			std::ostringstream oss;
			oss << std::put_time(&tm, "%Y-%m-%d");
			date = oss.str();
			it = this->_map.find(date);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			return (-1);
		}
	}

	return (it->second * value);
}

void BitcoinExchange::parseInput(std::string input_file)
{
	double	value;
	double price;
	std::ifstream ifs(input_file);
	std::string line;

	if (!ifs.is_open())
		std::cerr << "Error opening ifs." << std::endl;
	else
	{
		while (std::getline(ifs, line))
		{
			std::istringstream lineStream(line);
			std::string dateStr, valueStr;
			if (std::getline(lineStream, dateStr, '|') )
			{
				if (std::getline(lineStream, valueStr, '|'))
				{
					try
					{
						while (dateStr.find_first_of("\n\r\t\v\f ") != std::string::npos)
							dateStr.erase(dateStr.find_first_of("\n\r\t\v\f "), 1);
						value = std::stod(valueStr);
						if (value < 0)
							throw std::runtime_error("not a positive number.");
						if (value >= 1000)
							throw std::runtime_error("too large a number.");
						price = this->getPrice(dateStr, value);
						if (price < 0)
							continue;
						std::cout << dateStr << " => " << value << " = " << price << std::endl;
					}
					catch (const std::exception &e)
					{
						std::cerr << "Error parsing line: " << e.what() << std::endl;
					}
				}
				else
					std::cerr << "Error parsing line: Expected a value." << std::endl;
			}
			else
				std::cerr << "Error parsing line: Expected a date." << std::endl;
		}
		ifs.close();
	}
}
