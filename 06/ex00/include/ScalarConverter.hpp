#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>

class ScalarConverter
{
  public:
	static void convert(std::string str);

  private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &scalarconverter);
	ScalarConverter &operator=(const ScalarConverter &scalarconverter);
	~ScalarConverter();
};

#endif
