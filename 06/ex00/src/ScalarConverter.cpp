#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	// std::cout << "ScalarConverter: Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	// std::cout << "ScalarConverter: Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarconverter)
{
	// std::cout << "ScalarConverter: Copy constructor called" << std::endl;
	*this = scalarconverter;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &scalarconverter)
{
	// std::cout << "ScalarConverter: Copy assignment operator called" << std::endl;
	(void)scalarconverter;
	return (*this);
}

static void printChar(char c)
{
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void printInt(double i)
{
	if (i != i)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(i) << std::endl;
}

static void printFloat(float f)
{
	std::cout << "float: " << f << "f" << std::endl;
}

static void printDouble(double d)
{
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	std::cout << std::setprecision(2) << std::fixed;
	if (str.length() == 1 && !isdigit(str[0]))
	{
		char c = str[0];
		printChar(static_cast<char>(c));
		printInt(static_cast<double>(c));
		printFloat(static_cast<float>(c));
		printDouble(static_cast<double>(c));
		return ;
	}
	try
	{
		float f = std::stof(str);
		printChar(static_cast<char>(f));
		printInt(static_cast<double>(f));
		printFloat(static_cast<float>(f));
		printDouble(static_cast<double>(f));
	}
	catch (std::exception &e)
	{
		try
		{
			double d = std::stod(str);
			printChar(static_cast<char>(d));
			printInt(static_cast<double>(d));
			printFloat(static_cast<float>(d));
			printDouble(static_cast<double>(d));
		}
		catch (std::exception &e)
		{
			try
			{
				int i = std::stoi(str);
				printChar(static_cast<char>(i));
				printInt(static_cast<double>(i));
				printFloat(static_cast<float>(i));
				printDouble(static_cast<double>(i));
			}
			catch (std::exception &e)
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
			}
		}
	}
}
