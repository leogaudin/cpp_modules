#include "../include/AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal: Default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type)
{
	std::cout << "AAnimal: Default constructor called" << std::endl;
	this->type = type;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal: Destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &animal)
{
	std::cout << "AAnimal: Copy constructor called" << std::endl;
	*this = animal;
}

AAnimal &AAnimal::operator=(const AAnimal &animal)
{
	std::cout << "AAnimal: Copy assignment operator called" << std::endl;
	this->type = animal.type;
	return (*this);
}

std::string AAnimal::getType() const
{
	return (this->type);
}
