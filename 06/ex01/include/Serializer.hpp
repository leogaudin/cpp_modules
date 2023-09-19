#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iomanip>
# include <iostream>

struct		Data
{
	std::string name;
	double	price;
};

class Serializer
{
  public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

  private:
	Serializer();
	Serializer(const Serializer &scalarconverter);
	Serializer &operator=(const Serializer &scalarconverter);
	~Serializer();
};

#endif
