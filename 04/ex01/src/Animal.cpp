#include "../include/Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
	std::cout << "Animal: Default constructor called" << std::endl;
	this->type = type;
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Animal: Copy constructor called" << std::endl;
	*this = animal;
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "Animal: Copy assignment operator called" << std::endl;
	this->type = animal.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Animal: makeSound: Unknown animal" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}
