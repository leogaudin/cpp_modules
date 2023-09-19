#include "../include/Serializer.hpp"

Serializer::Serializer()
{
	// std::cout << "Serializer: Default constructor called" << std::endl;
}

Serializer::~Serializer()
{
	// std::cout << "Serializer: Destructor called" << std::endl;
}

Serializer::Serializer(const Serializer &serializer)
{
	// std::cout << "Serializer: Copy constructor called" << std::endl;
	*this = serializer;
}

Serializer &Serializer::operator=(const Serializer &serializer)
{
	// std::cout << "Serializer: Copy assignment operator called" << std::endl;
	(void)serializer;
	return (*this);
}

uintptr_t Serializer::serialize(Data *data)
{
	return (reinterpret_cast<uintptr_t>(data));
}

Data *Serializer::deserialize(uintptr_t data)
{
	return (reinterpret_cast<Data *>(data));
}
